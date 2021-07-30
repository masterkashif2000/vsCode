#include<iostream>
using namespace std;
typedef long long int ll;

//ll dp[1000000]={0};
ll dp[1000000];

int fib(ll n,ll dp[]){
    //base case
    if(n==0||n==1){
        return n;
    }
    //lookup
    if(dp[n]!=0){
        return dp[n];
    }
    //ll ans;
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
    //return dp[n]=ans;
}

int main(){
    ll n;
    cin>>n;
    /*for(ll i=0;i<n;i++){
        cout<<fib(i)<<" ";
    }*/
    //ll dp[100]={0};
    cout<<fib(n,dp)<<endl;

}
