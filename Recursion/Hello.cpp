#include<bits/stdc++.h>
using namespace std;
void printHello(int n){
    if(n == 0){
        return;
    }
    cout<<n<<" Hello!"<<endl;
    printHello(n-1);
}
int main(){
    printHello(5);
}