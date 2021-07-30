#include<iostream>
using namespace std;
typedef long long int ll;

int fib(int n){
    //base case
    if(n==0||n==1){
        return n;
    }
    //recursive case
    return fib(n-1)+fib(n-2);
}

int main(){
    ll n;
    cin>>n;
    /*for(ll i=0;i<n;i++){
        cout<<fib(i)<<" ";
    }*/
    cout<<fib(n)<<endl;

    return 0;
}
