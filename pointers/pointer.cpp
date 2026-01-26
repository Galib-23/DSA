#include<bits/stdc++.h>
using namespace std;


int main() {
  int x = 4;
  int *px = &x;

  cout<<px<<endl;
  cout<<*px<<endl;
  cout<<*(&x)<<endl;

  cout<<&(*px)<<endl;
}