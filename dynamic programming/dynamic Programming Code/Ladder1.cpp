Problem Name : Ladder-I
Topic : DP
Difficulty : Hard
EXPLANATION
From each position 'i' you have choice to jump to position 'j' such that 'j'-'i'<=k. Let's define dp[i] as number of ways to reach end from position i. By now, recursion is quite obvious which is: dp[i]=sum(dp[j]) , i+1<=j<=n.

Time Complexity : O(N*KN∗K).
#include<bits/stdc++.h>
using namespace std;

int dp[100001];

const int mod = 1e9+7;

int MOD(int a){
    return (a-((a/mod)*mod));
}

int NumberOfWays(vector<int> &cells,int pos,int k){
    if(pos>=cells.size() || cells[pos]){
        return 0;
    }
    if(pos==cells.size()-1){
        return 1;
    }
    int &res=dp[pos];
    if(res!=-1){
        return res;
    }

    res=0;
    for(int next_cell=pos+1;next_cell-pos<=k;next_cell++){
        if(next_cell>cells.size())break;
        res+=(NumberOfWays(cells,next_cell,k));
        res=MOD(res);
    }
    return res;
}

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> cells(n);
    for(int i=0;i<n;i++){
        cin>>cells[i];
    }

    memset(dp,-1,sizeof dp);

    cout<<NumberOfWays(cells,0,k)<<endl;

}
Approach 2
//Rajkishor Ranjan
#include <bits/stdc++.h>
#define ff first
#define se second
#define pb push_back
#define nn 6000
#define mt make_tuple
#define mp make_pair
#define ll long long int
#define db double
#define ldb long double
#define inf 1000000000000000000ll
#define logn 20
#define mod 1000000007ll
#define mod1 mod
#define mod2 100000009ll
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define init(a) memset(a,-1,sizeof a)
#define cmp 1e-16

using namespace std;

ll dp[nn];
bool a[nn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=0;
        if(a[i])
            continue;
        for(int j=i-1;j>=max(0,i-k);j--)
        {
            dp[i]=(dp[i]+dp[j])%mod;
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
💡 LADDER -I

