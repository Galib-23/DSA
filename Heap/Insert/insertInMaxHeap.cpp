#include<bits/stdc++.h>
using namespace std;

void insert(int a[], int n, int value){
    n = n + 1;
    a[n] = value;
    int i = n;
    while( i > 1 ){
        int parent = i / 2;
        if(a[parent] < a[i]){
            swap(a[parent], a[i]);
            i = parent;
        }
        else return;
    }
}

int main(){
    int a[] = {50, 30, 40, 10, 5, 20, 30, 60};
    int value = 45;
    int n = sizeof(a) / sizeof(a[0]);
    insert(a, n, value);
    for(auto i: a){
        cout<<i<<" ";
    }cout<<endl;
}