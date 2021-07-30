// Problem Name : Coin Change
// Topic : DP
// Difficulty : Medium
// EXPLANATION
// Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5. 1) Optimal Substructure To count the total number of solutions, we can divide all set solutions into two sets. 1) Solutions that do not contain mth coin (or Sm). 2) Solutions that contain at least one Sm. Let count(S[], m, n) be the function to count the number of solutions, then it can be written as sum of count(S[], m-1, n) and count(S[], m, n-Sm).

// Therefore, the problem has optimal substructure property as the problem can be solved using solutions to subproblems.

// Time Complexity : O(N*MN∗M).
#include<bits/stdc++.h>
using namespace std;

int dp[100][500];

int NumberOfWays(vector<int> &coins,int N,int pos){
    int &res=dp[pos][N];
    if(res!=-1){
        return res;
    }
    if(N==0){
        return 1;
    }
    if(pos==coins.size()){
        if(N)return 0;
        else return 1;
    }
    res=0;
    res=NumberOfWays(coins,N,pos+1);
    if(N>=coins[pos])
        res+=NumberOfWays(coins,N-coins[pos],pos);
    return res; 
}

signed main(){    

    int n,m;
    cin>>n>>m;
    vector<int> coins(m);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    memset(dp,-1,sizeof dp);

    cout<<NumberOfWays(coins,n,0)<<endl;

    return 0;
}
//Approach 2

// #include <iostream>

// using namespace std;

// long long int dp[1005];
// long long int count( long long int S[], long long int m, long long int n )
// {
//     dp[0] = 1;
//     for(int i=0; i<m; i++)
//         for(int j=S[i]; j<=n; j++)
//             dp[j] += dp[j-S[i]];

//     return dp[n];
// }

// int main()
// {
//     long long int val[1005];
//     //freopen("test.txt", "r", stdin);
//     //freopen("output.txt", "w", stdout);
//     int  N,M;
//     scanf("%d%d",&N,&M);
//     for(int i=0; i<M ;++i)
//         scanf("%lld",&val[i]);
//     cout<<count(val,M,N);
//     return 0;
// }