Problem Name : Edit Distance
Topic : DP
Difficulty : Hard
EXPLANATION
What are the subproblems in this case? The idea is process all characters one by one staring from either from left or right sides of both strings. Let us traverse from right corner, there are two possibilities for every pair of character being traversed.

m: Length of str1 (first string) n: Length of str2 (second string) If last characters of two strings are same, nothing much to do. Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1. Else (If last characters are not same), we consider all operations on ‘str1’, consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values. Insert: Recur for m and n-1 Remove: Recur for m-1 and n Replace: Recur for m-1 and n-1

Time Complexity : O(N*MN∗M).
#include<bits/stdc++.h>
using namespace std;

int EditDistance(string &a,string &b){
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];
    memset(dp,(int)INT_MAX,sizeof dp);

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else{
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=dp[i][j-1]+1;
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
    }

    return dp[n][m];
}

int main(){
    string a,b;
    cin>>a>>b;
    cout<<EditDistance(a,b)<<endl;
    return 0;
}
Approach 2
#include <bits/stdc++.h>
#define ff first
#define se second
#define pb push_back
#define nn 2001
#define mt make_tuple
#define mp make_pair
#define ll long long int
#define db double
#define ldb long double
#define inf 1000000000000000000ll
#define logn 20
#define mod 341550071728321ll
#define mod1 mod
#define mod2 3825123056546413051ll
#define sqr(a) a*1ll*a
#define nullp mp(-1,-1)
#define set0(a) memset(a,0,sizeof a)
#define init(a) memset(a,-1,sizeof a)
#define cmp 1e-11
#define pll pair<ll,ll>
#define pbc pop_back

using namespace std;
const ldb pi=3.141592653589793238462643383;

int dp[nn][nn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    for(int i=0;i<=n;i++)
        dp[i][0]=i;
    for(int i=0;i<=m;i++)
        dp[0][i]=i;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i+1][j+1]=dp[i][j];
            }
            else
                dp[i+1][j+1]=min(dp[i+1][j],min(dp[i][j+1],dp[i][j]))+1;
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}