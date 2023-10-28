/*
 Q. Find all the permutations of a given string

    ab -> [ab, ba]
    abc -> [abc, acb, bac, bca, cab, cba]
*/

#include<bits/stdc++.h>
using namespace std;
/*
    fixing one character and appending another at the last. and doing it for subproblems also
                        abc
                    /    |     \
                 a(bc)  b(ac)    c(ba)
               /  \     / \       /   \
         ab(c) ac(b) ba(c) bc(a) cb(a) ca(b)
*/

void permute(string s, int l, int r){
    if(l == r){
        cout<<s<<" ";
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(s[l], s[i]);
        permute(s, l+1, r);
        swap(s[l], s[i]);
    }
}

int main(){
    string s = "abc";
    permute(s, 0, s.size()-1);
}