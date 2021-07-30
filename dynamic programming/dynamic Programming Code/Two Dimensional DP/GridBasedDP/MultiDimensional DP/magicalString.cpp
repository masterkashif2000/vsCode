/*input
5
aabab
2 3 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define F(i,a,b) for(ll i = a; i <= b; i++)
#define RF(i,a,b) for(ll i = a; i >= b; i--)
#define pii pair<ll,ll>
#define PI 3.14159265358979323846264338327950288
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define debug(x) cout << #x << " = " << x << endl
#define INF 1000000009
#define mod 1000000007
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
ll n,arr[30],dp[1005],maxlen;
string s;
bool isvalid(ll st,ll en) // fucntion to check if letter satisfies the given constraint
{
    F(i,st,en)
    {
        if(arr[s[i]-'a'] < (en-st+1)) // st and en and starting and ending indexes of string
            return 0;
    }
    return 1;
}
ll f(ll cur) //recursive top down solution (cur is the current index)
{
    if(dp[cur] != -1) // if already calculated
        return dp[cur];
    if(cur == 0) // termination
        return dp[cur] = 1; // since there is 1 way to split a string of length null
    ll ans = 0;
    RF(i,cur,1) // iterate until you can
    {
        if(isvalid(i,cur))
        {
            maxlen = max(maxlen,cur-i+1);
            ans += f(i-1);
            ans %= mod;
        }
    }
    return dp[cur] = ans; // store ans in dp
}
ll dp1[1005];
int main() 
{
    std::ios::sync_with_stdio(false);
    //memset(dp,-1,sizeof(dp));
    cin>>n>>s;
    s = "*" + s; // making string 1 indexed
    F(i,0,25)
        cin>>arr[i];
    //cout<<f(n)<<endl;
    dp1[0] = 1; // bottom up dp solution
    F(i,1,n)
    {
        RF(j,i,1)
        {
            if(isvalid(j,i)) // is substring [j..i] is valid
            {
                maxlen = max(maxlen,i-j+1);
                dp1[i] += dp1[j-1];
                dp1[i] %= mod;
            }
        }
    }
    cout<<dp1[n]<<endl;
    //cout<<maxlen<<endl;
    return 0;
}