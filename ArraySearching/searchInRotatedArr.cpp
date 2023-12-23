/*
    Rotated Array: 6, 7, 1, 2, 3, 4, 5   --->> This is Two times Rotated
                   5, 6, 7, 1, 2, 3, 4   --->> This is 3 Times Rotated
                   4, 5, 6, 7, 1, 2, 3   --->> This is 4 times Rotated
                
                   We find the middle element and see if the left most element is less than the middle element then the left part is sorted,
                   else the right part is sorted.

                   if the key is in the sorted part we discard the unsorted part
                   and apply binary search. Else we find the middle element in the unsorted part again and do it recursively.
*/
#include<bits/stdc++.h>
using namespace std;
int binarySearchInRotated(int a[], int low, int high, int key){
    while(high >= low){
        int mid = (low + high) / 2;
        if(a[mid] == key) return mid;
        if(a[low] < a[mid]){
            if(key >= a[low] and key < a[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(key <= a[high] and key > a[mid]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
}
int main(){
    int a[] = {6, 7, 1, 2, 3, 4, 5};
    int n = sizeof(a)/sizeof(a[0]);
    int high = n - 1;
    int low = 0;
    int key = 4;
    int res = binarySearchInRotated(a, low, high, key);
    cout<<"Position of key is : "<<res<<endl;
}
