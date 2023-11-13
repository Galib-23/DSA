//Search an element in an infinitely sorted array where the array length is unknown
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int a[], int low, int high, int key){
    int mid = (high + low) / 2;
    if(a[mid] == key) return mid;
    else if(key > a[mid]){
        return binarySearch(a, mid + 1, high, key);
    }
    else return binarySearch(a, low, mid - 1, key);
    return 0;
}
int searchInfinite(int a[], int key){
    int low = 0;
    int high = 1;
    while(a[high] < key){
        low = high;
        high = high * 2;
    }
    return binarySearch(a, low, high, key);
}
int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ,13, 14, 15, 16, 17, 18 ,19, 20, 21, 22, 23, 24, 25};
    int n = sizeof(a) / sizeof(a[0]);
    int res = searchInfinite(a, 15);
    cout<<"Position of the element is: "<<res<<endl;
}