#include<bits/stdc++.h>
using namespace std;
int partition(int a[], int low, int high){
    int pivot = low;
    int i = low;
    int j = high;
    while (i<j)
    {
        while(a[i] < a[pivot]){
            i++;
        }
        while (a[j] > a[pivot])
        {
            j--;
        }
        swap(a[i], a[j]);
    }
    swap(a[pivot], a[j]);
    return j;
}
void quickSort(int a[], int l, int h){
    if(l < h){
        int pvt = partition(a, l, h);
        quickSort(a, l, pvt - 1);
        quickSort(a, pvt + 1, h);
    }
}
int main(){
    int a[] = {4, 3, 2, 1, 6, 5, 8, 10, 7, 9};
    int n = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}