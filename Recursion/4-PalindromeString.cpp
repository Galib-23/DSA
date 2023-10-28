/*
    Q. Finding if a string is palindrome or not using Recursion.
*/
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int l, int r){
    if(l >= r) {    //(l == r) this  condition is not applicable for strings of even size
        return true;
    }
    if(s[l] != s[r]){
        return false;
    }
    return isPalindrome(s, l+1, r-1);
}

int main(){
    string s = "abba" ;
    bool res = isPalindrome(s, 0, s.size() - 1);
    if(res){
        cout<<"Palindrome"<<endl;
    }
    else cout<<"Not Palindrome"<<endl;
}