#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int mid, int r){
    int b[100];
    int i = l;
    int j = mid + 1;
    int k = l;
    while(i <= mid && j <= r){
        //compare the right and left subarray and put the smallest in the temporary array b.
        if(a[i] <= a[j]){
            b[k] = a[i];
            i++;
        }else{
            b[k] = a[j];
            j++;
        } k++;
    }
    if(i > mid){
        while(j <= r){
            b[k] = a[j];
            j++; k++;
        }
    }else{
        while(i <= mid){
            b[k] = a[i];
            i++; k++;
        }
    }
    for (k = l; k <= r; k++)
    {
        a[k] = b[k];
    }
}
void mergeSort(int a[], int l, int r){
    if(l < r){ //at least two elements in the array
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}
int main(){
    int a[] = {3, 5, 4, 2, 1, 7, 6, 8};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}