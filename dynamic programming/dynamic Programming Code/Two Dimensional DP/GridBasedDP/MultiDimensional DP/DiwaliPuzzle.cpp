Problem Name : Diwali Puzzle (Celebration Time)
Topic : DP
Difficulty : Hard
EXPLANATION
This problem can be solved using dynamic programming. Let's define dp[i][prev][cnt] finds out how many combinations of these light bulbs of size n-i (on and off) will give the sum of products equal to given value cnt with last value as prev.
Then it's easy to see that our dp can be define as

if(prev==1){
    ans = ans + f(i+1,1,cnt+1);
}
else{
    ans = ans + f(i+1,1,cnt);
}
Time Complexity : O(N*xN∗x).
#include<iostream>
#include<cstring>
using namespace std;

#define ll long long 
#define mod 1000003

ll n,x;
ll dp[105][3][105];

ll f(ll i,ll prev,ll cnt)
{
    //Base Case 
    if(i==n){
        if(cnt==x){
            return 1;
        }
        return 0;
    }
    //Top Down dp
    if(dp[i][prev][cnt]!=-1){
        return dp[i][prev][cnt];
    }

    ll ans = 0;

    if(prev==1){
        ans = ans + f(i+1,1,cnt+1);
    }
    else{
        ans = ans + f(i+1,1,cnt);
    }

    ans %= mod;

    //when current element we put is zero
    ans = ans + f(i+1, 0,cnt);
    ans %= mod;

    return dp[i][prev][cnt] = ans;

}


int main() 
{
    ll t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n>>x;
        cout<<(f(1,0,0) + f(1,1,0))%mod<<endl; // start by both choice with first value either 0 or 1
    }
    return 0;
}
💡 Diwali Puzzle