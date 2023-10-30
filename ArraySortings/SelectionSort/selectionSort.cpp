#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {3, 2, 4, 5, 1};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; // let the first index be the minimum element's index
        for (int j = i+1; j < n; j++)
        {
            if(a[j] < a[minIndex]){ //if any other element after the first index is lesser than change the minIndex
                minIndex = j;
            }
        }
        if(minIndex != i){
            swap(a[i], a[minIndex]); //swap the minimum index's element with the i'th element
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}