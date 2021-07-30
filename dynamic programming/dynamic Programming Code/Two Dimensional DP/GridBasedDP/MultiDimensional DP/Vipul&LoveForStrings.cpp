Problem Name : Vipul and his love for strings
Topic : DP
Difficulty : Hard
EXPLANATION
Let's use the method of dynamic programming. Let d[i][j][cnt][end] be answer to the problem for the prefix of string s of length i and for the prefix of string t of length j, we have chosen cnt substrings. end = 1, if both last characters of the prefixes are included in the maximum subsequence and end = 0 otherwise.

When the state is d[i][j][cnt][end], you can add the following letters in the string s or t, though it will not be included in the response subsequence. Then d[i + 1][j][cnt][0] = max(d[i + 1][j][cnt][0], d[i][j][cnt][end]), d[i][j + 1][cnt][0] = max(d[i][j + 1][cnt][0], d[i][j][cnt][end]). So the new value of end is 0, because the new letter is not included in the response subsequence.

If s[i] = t[j], then if end = 1, we can update the d[i + 1][j + 1][k][1] = max(d[i][j][k][end] + 1, d[i + 1][j + 1][k][1]). When we add an element to the response subsequence, the number of substring, which it is composed, will remain the same, because end = 1. If end = 0, we can update d[i + 1][j + 1][k + 1][1] = max(d[i][j][k][end] + 1, d[i + 1][j + 1][k + 1][1]). In this case, the new characters, which we try to add to the response subsequence, will form a new substring, so in this case we do the transition from the state k to the state k + 1.

The answer will be the largest number among the states of the d[n][m][k][end], where the values ​​of k and end take all possible values.

Time Complexity : O($$nmk$$).
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nn 2000005
string a,b;
ll n,m,k;
ll dp[1005][ 1005 ][ 11 ][ 2 ];
ll solve ( ll ia, ll ib, ll subs, ll cont )
{
    if ( subs < 0 )
        return INT_MIN;
    if ( ia == a.size() or ib == b.size() )
    {
        if ( subs == 0 )
        {
            return 0;
        }
        else
            return INT_MIN;
    }
    if ( dp[ia][ib][subs][cont] != - 1)
        return dp[ia][ib][subs][cont];
    ll ret = INT_MIN;
    if ( cont == 1 )
    {
        if ( a[ia] == b[ib] )
        {
            ret = max(1+solve(ia+1,ib+1,subs,1),max(solve(ia+1,ib,subs-1,0),solve(ia,ib+1,subs-1,0)));
            ret = max(ret,1+solve(ia+1,ib+1,subs-1,0));
        }
        else
            ret = max(solve(ia+1,ib,subs,0),solve(ia,ib+1,subs,0));
    }
    else
    {
        if ( a[ia] == b[ib] )
        {
            ret = max(1+solve(ia+1,ib+1,subs-1,1),max(solve(ia+1,ib,subs,0),solve(ia,ib+1,subs,0)));
            ret = max(ret,1+solve(ia+1,ib+1,subs-1,0));
        }
        else
            ret = max(solve(ia+1,ib,subs,0),solve(ia,ib+1,subs,0));
    }   
    return dp[ia][ib][subs][cont] = ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,-1,sizeof dp);
    cin >> n >> m >> k;
    cin >> a >> b;
    cout << solve(0,0,k,0);

}

Approach 2
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 #define fio ios_base::sync_with_stdio(false)

#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)

#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)

#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

ll dp[1005][1005][15][2];
ll n,m;
string str1,str2;

ll solve(ll i,ll j,ll k,ll flag){
  if(k<0)return INT_MIN;
  if((i>=n or j>=m) and k==0)return 0;
  if((i>=n or j>=m) and k!=0)return INT_MIN;

  if(dp[i][j][k][flag] != -1)return dp[i][j][k][flag];

  ll ans = max(solve(i,j+1,k,0),solve(i+1,j,k,0));

  if(str1[i]==str2[j]){
    if(flag) ans=max(ans,1+solve(i+1,j+1,k,1));

    ans=max(ans,1+solve(i+1,j+1,k-1,1));
  }
  dp[i][j][k][flag]=ans;
  return ans;
}

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll k;
    memset(dp,-1,sizeof(dp));
    s3(n,m,k);
    cin>>str1>>str2;
    cout<<solve(0,0,k,0)<<endl;
  }
}