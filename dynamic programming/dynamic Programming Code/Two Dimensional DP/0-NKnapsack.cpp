Its an unbounded knapsack problem as we can use 1 or more instances of any resource. A simple 1D array, say dp[W+1] can be used such that dp[i] stores the maximum value which can achieved using all items and i capacity of knapsack.

dp[i] = 0

dp[i] = max(dp[i], dp[i-wt[j]] + val[j] where j varies from 0 to n-1 such that: wt[j] <= i

result = d[W]


int unboundedKnapsack(int *vals, int *wts, int W, int n) {
    int dp[W+1];
    memset(dp, 0, sizeof dp); 
    for(int i=0;i<=W;i++) {
        for(int j=0;j<n;j++) {
            if(wts[j]<=i)
                dp[i] = max(dp[i], dp[i-wts[j]]+vals[j]);
        }
    }

    return dp[W];
}

Lang - Java

    public static int unboundedKnapsack(int[] vals, int[] wts, int W, int n) {
        int[] dp = new int[W + 1];

        for (int i = 0; i <= W; i++) {
            for (int j = 0; j < n; j++) {
                if (wts[j] <= i)
                    dp[i] = Math.max(dp[i], dp[i - wts[j]] + vals[j]);
            }
        }

        return dp[W];
    }

C++
#include<bits/stdc++.h>
#define mod 1000000007
#define pp pair<ll,ll>
#define mp make_pair
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;

ll dp[1010][1010],n,cap,wt[1010],val[1010];
int main(){
//    freopen("input2.txt","r",stdin);
//    freopen("output2.txt","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n>>cap;
    for(int i=1;i<=n;i++)
        cin>>wt[i];
    for(int i=1;i<=n;i++)
        cin>>val[i];

    for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    for(int j=1;j<=cap;j++)
        dp[0][cap] = 0;

    for(int i=1;i<=cap;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i][j-1];
            if(wt[j] <= i)
                dp[i][j] = max(dp[i][j], val[j]+dp[i-wt[j]][j]);
        }
    }
    cout<<dp[cap][n];

    return 0;
}