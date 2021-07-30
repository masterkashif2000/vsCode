#include<iostream>
using namespace std;
typedef long long int ll;
ll dp[1000]={0};
 int fib(int n){
    //ll dp[1000]={0};
    dp[0]=0;
    dp[1]=1;
    //lookup
    if(dp[n]!=0){
        return dp[n];
    }
    for(ll i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
 }

int main(){
    ll n;
    cin>>n;
    /*for(ll i=0;i<n;i++){
        cout<<fib(i)<<" ";
    }*/
    //ll dp[100]={0};
    cout<<fib(n)<<endl;

}
