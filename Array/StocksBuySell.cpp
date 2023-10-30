 /*
    Q. An array given where each element denotes the price of stock on that day of index.
    Find the prices in which if we buy and sell we will get the maximum profit.
    ex: an array a = {3, 1, 4, 8, 7, 2, 5}
    here if we buy at 1 and sell at 8 we get maximum profit.
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {3, 1, 4, 8, 7, 2, 5};
    int size = sizeof(a)/sizeof(a[0]);
    int minSoFar = a[0];
    int maxProfit = 0;
    for (int i = 0; i < size; i++)
    {
        minSoFar = min(minSoFar, a[i]);
        int profit = (a[i] - minSoFar);
        maxProfit = max(maxProfit, profit);
    }
    cout<<"max profit is : "<<maxProfit<<endl;
}