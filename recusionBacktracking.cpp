#include<iostream>
using namespace std;
void f(int n){
    if(n != 0)
        f(n-1);
    if(n == 0 )
        return;
    cout<<n;
}
int main(){
    int n;
    cin>>n;
    f(n);
}