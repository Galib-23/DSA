
#include<bits/stdc++.h>
using namespace std;

void printOneToN(int n) {
  if(n == 1) {
    cout<<n<< " ";
    return;
  };
  printOneToN(n - 1);
  cout<<n<<" ";
  return;
}

int main(){
  printOneToN(8);
}