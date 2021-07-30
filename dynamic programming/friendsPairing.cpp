#include<iostream>
using namespace std;
typedef long long int ll;

ll Pairing(ll n){
    ll dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(ll i=3;i<=n;i++){
        dp[i]=dp[i-1]+((i-1)*dp[i-2]);
    }
    return dp[n];
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        cout<<Pairing(n)<<endl;
    }
}