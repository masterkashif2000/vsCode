#include<bits/stdc++.h>
using namespace std;

typedef int ll;

ll m = pow(10,9) + 7;

ll a,b,n1,n2;

ll dp[1005][1005][25][2];

// 0 - Diya 1 - Candle
ll func(ll d,ll c, ll n,ll x)
{
    if (d==0 && c==0) return 1;
    if (dp[d][c][n][x]!=-1) return dp[d][c][n][x];
    ll ans = 0;
    if (d>0)
    {
        if (x==0 && n<n1) ans = ( ans + func(d-1,c,n+1,0) )%m ;
        if (x==1) ans = ( ans + func(d-1,c,1,0) )%m;
    }
    if (c>0)
    {
        if (x==1 && n<n2) ans = ( ans + func(d,c-1,n+1,1)  )%m;
        if (x==0) ans = ( ans + func(d,c-1,1,1) )%m;
    }
    return dp[d][c][n][x] = ans;
}

int main()
{
    scanf("%d %d %d %d",&a,&b,&n1,&n2);
    memset(dp,-1,sizeof(dp));
    printf("%d",func(a,b,0,0));
    return 0;
}  