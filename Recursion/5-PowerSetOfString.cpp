/*
    Sub-sequences of abc = {"", a, b, c, ab, bc, ca, abc} 
    so, total 8 subsequences
*/

#include<bits/stdc++.h>
using namespace std;

/*
                    abc
                   / \
                 a     ""
               /   \    /  \
              ab   a    b    ""
            /  \  / \  / \    / \
           abc ab ac a bc b  c   ""
           [This is produced by taking a character and not taking. Then move to next character of the string]
*/
void powerSet(string s, int i, string current){
    if(i == s.size()){
        cout<<current<<" ";
        return;
    }
    powerSet(s, i+1, current + s[i]);
    powerSet(s, i+1, current);
}

int main(){
    string s = "abcd";
    string current = "";
    powerSet(s, 0, current);
}

