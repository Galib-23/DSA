#include <stdio.h>
#include <stdlib.h>

int main() {
    int number;
    printf("Enter total students: ");
    scanf("%d", &number);

    int *rolls = malloc(number * sizeof(int));
    if (rolls == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < number; i++) {
        printf("Enter roll: ");
        scanf("%d", &rolls[i]);
    }

    printf("Roll numbers: ");
    for (int i = 0; i < number; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");

    free(rolls);
    rolls = NULL; // avoid dangling pointer

    return 0;
}
