#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = { 2, 3, 5, 6 ,8, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int sum = 18;
    int currentSum = 0;
    int start = 0;
    int end = -1;

    unordered_map<int, int> hashMap;

    for (int i = 0; i < n; i++)
    {
        currentSum = currentSum + a[i];

        if(currentSum == sum){
            start = 0;
            end = i;
        }
        else if(hashMap.find(currentSum - sum) != hashMap.end()){
            start = hashMap[currentSum - sum] + 1;
            end = i;
        }
        hashMap[currentSum] = i;
    }
    cout<<"Start index: "<<start<<endl<<"End index: "<<end<<endl;
}