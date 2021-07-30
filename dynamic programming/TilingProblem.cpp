#include<iostream>
using namespace std;

int Ways(int n,int m){
    //Bottom Up Approach
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        if(i>m){
            dp[i]=dp[i-1]+dp[i-m];
        }
        else if(i<m||i==1){
            dp[i]=1;
        }
        else{
            dp[i]=2;
        }
    }
    return dp[n];
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    int n,m;
    cin>>n>>m;
    int d=Ways(n,m);
    cout<<d<<endl;
    // cout<<"Total  number of ways of tiling the wall which is n*m is:"<<d<<endl;
    }
}