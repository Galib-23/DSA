#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"root is : "<<sqrt(n)<<endl;
    int count = 0;
    int lim = sqrt(n);
    for (int i = 2; i <=lim; i++)
    {
        if(n%i == 0){
            count++;
            break;
        }
    }
    if(count > 0) cout<<"Not Prime"<<endl;
    else cout<<"Prime"<<endl;
}