#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define fre     freopen("input-1.txt","r",stdin),freopen("output-1.txt","w",stdout)
#define abs(x) ((x)>0?(x):-(x))
#define M 1000000007
#define lld signed long long int
#define pp pop_back()
#define ps(x) push_back(x)
#define mpa make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define scan(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define scanll(x) scanf("%lld",&x)
#define printll(x) printf("%lld\n",x)
#define boost ios_base::sync_with_stdio(0)
//vector<int> g[2*100000+5];int par[2*100000+5];
lld dp[1048576+5][22];
int freq[1048576+5]{0};
int d[1000000+5]{0};
int main()
{
    int t;
    t=1;
    while(t--)
    {
        int n,x,mask;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            scan(d[i]);
        }
        for(int i=1;i<=n;i++){
            d[i]=d[i-1]+d[i];
            freq[d[i]]++;
        }
        lld ans=0;
        for(int mask=0;mask<(1ll<<20);++mask)
        {
            dp[mask][0]=freq[mask];
            if(mask&1)
                dp[mask][0]+=freq[mask^1];
            for(int p=1;p<=20;++p)
            {
                dp[mask][p]=dp[mask][p-1];
                if(mask&(1<<p))
                {
                    dp[mask][p]+=dp[mask^(1<<p)][p-1];
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            ans+=dp[(1LL<<20LL)-1LL-d[i]][20];
            freq[d[i]]--;
        }
        cout<<ans/2<<endl;
    }
}