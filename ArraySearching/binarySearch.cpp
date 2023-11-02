//This sorting technique only works for sorted arrays
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int a[], int l, int h, int key){
    int mid = (l + h) / 2;
    if(a[mid] == key){
        return mid;
    }
    else if(key > a[mid]){
        return binarySearch(a, mid+1, h, key);
    }
    else {
        return binarySearch(a, l, mid-1, key);
    }
    return 0;
}
int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    int res = binarySearch(a, 0, n-1, 7);
    cout<<"Position of the element is: "<<res<<endl;
}