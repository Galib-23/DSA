#include<bits/stdc++.h>
using namespace std;

// We can only delete root node from max heap
void del(int a[], int n){
    a[1] = a[n]; // always one based indexing in heap || replacing with first element
    n = n - 1;
    int i = 1; // always one based indexing in heap
    while (i < n)
    {
        int left = a[2 * i];
        int right = a[2 * i + 1];
        int larger = left > right ? 2*i : 2*i + 1;
        if(a[i] < a[larger]){
            swap(a[i], a[larger]);
            i = larger;
        }
        else{
            return;
        }
    }
}
int main(){
    int a[] = {0, 50, 30, 40, 10, 5, 20, 30};
    int n = sizeof(a) / sizeof(a[0]); // We can only delete root node from max heap

    del(a, n-1); // always one based indexing in heap
    for (int i = 1; i < n; i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    
}