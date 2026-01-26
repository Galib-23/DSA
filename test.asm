; Fixed Assembly Web Server
; Build:
; nasm -f elf64 webserver.asm -o webserver.o
; ld webserver.o -o webserver
; sudo ./webserver
; Then: curl http://127.0.0.1:8080

section .data
    ; JSON response body
    json_body db '{"message":"Hello from Assembly!"}',0
    json_len  equ $-json_body - 1
    
    ; HTTP response headers
    response db "HTTP/1.1 200 OK",13,10
             db "Content-Type: application/json",13,10
             db "Content-Length: "
    response_len equ $-response
    
    ; Content-Length value and header separator
    content_length db "33",13,10,13,10
    content_length_len equ $-content_length

    ; Socket address structure (sockaddr_in)
    ; IMPORTANT: Must be in .data section, not .text!
    addr:
        dw 2              ; sin_family: AF_INET (IPv4)
        dw 0x901F         ; sin_port: 8080 in network byte order
        dd 0x0100007F     ; sin_addr: 127.0.0.1 in network byte order
        dq 0              ; sin_zero: padding to 16 bytes

section .bss
    client_fd resq 1      ; Storage for client socket file descriptor

section .text
global _start

_start:
    ; 1. Create socket: socket(AF_INET, SOCK_STREAM, 0)
    mov rax, 41           ; syscall number for socket()
    mov rdi, 2            ; AF_INET (IPv4)
    mov rsi, 1            ; SOCK_STREAM (TCP)
    xor rdx, rdx          ; protocol = 0 (default)
    syscall
    mov r12, rax          ; Save server socket fd in r12

    ; 2. Bind socket to address: bind(sockfd, addr, addrlen)
 
    mov rdi, r12  
    lea rsi, [rel addr] 
    mov rdx, 16         
    mov rax, 49           
    syscall

    ; 3. Listen for connections: listen(sockfd, backlog)
    mov rdi, r12          ; server socket fd
    mov rsi, 5            ; backlog (max pending connections)
    mov rax, 50           ; syscall number for listen()
    syscall

accept_loop:
    ; 4. Accept connection: accept(sockfd, NULL, NULL)
    mov rdi, r12          ; server socket fd
    xor rsi, rsi          ; addr = NULL (we don't need client info)
    xor rdx, rdx          ; addrlen = NULL
    mov rax, 43           ; syscall number for accept()
    syscall
    mov [client_fd], rax  ; Save client socket fd

    ; 5. Send HTTP headers
    mov rdi, [client_fd]  ; client socket fd
    lea rsi, [rel response]
    mov rdx, response_len
    mov rax, 1            ; syscall number for write()
    syscall

    ; 6. Send Content-Length and blank line
    mov rdi, [client_fd]
    lea rsi, [rel content_length]
    mov rdx, content_length_len
    mov rax, 1
    syscall

    ; 7. Send JSON body
    mov rdi, [client_fd]
    lea rsi, [rel json_body]
    mov rdx, json_len
    mov rax, 1
    syscall

    ; 8. Close client connection: close(fd)
    mov rdi, [client_fd]
    mov rax, 3            ; syscall number for close()
    syscall

    ; Loop back to accept next connection
    jmp accept_loop