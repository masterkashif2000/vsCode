The first thing to notice here is that if we mix mixtures i..j into a single mixture, irrespective of the steps taken to achieve this, the final color of the mixture is same and equal to sum(i, j) = sum(color[i]..color[j]) mod 100.
So, we define dp(i,j) as the most optimum solution where least amount of smoke is produced while mixing the mixtures from i..j intro a single mixture, For achieving this, at the previous steps, we would have had to combine the two mixtures which are resultant of the range i..k and k+1..j where i<=k<=j.
So, its about splitting the mixture into 2 subsets and each subset into 2 more subsets and so on such that smoke produced is minimised, Hence the recurrence relation will be: dp(i,j) = min(k: i<= k < j) { dp(i,k)+dp(k+1, j)+sum(i,k)*sum(k+1,j) }



#include<bits/stdc++.h>
using namespace std;

long long n,i,j,a[110],dp[110][110],temp,k,l,sum[110][110];

int main(){
//    freopen("input5.txt","r",stdin);
//    freopen("output5.txt","w",stdout);
//    ios::sync_wth_stdio(0);

    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++){
        sum[i][i]=temp = a[i];
        for(j=i+1;j<n;j++){
            temp += a[j];
            sum[i][j] = temp%100;
        }
    }
    for(i=0;i<n;i++)
        dp[i][i] = 0;
    for(j=1;j<n;j++){
        for(i=0;i<n-j;i++){
            dp[i][i+j] = INT_MAX;
            for(k=i;k<i+j;k++){
                dp[i][i+j] = min(dp[i][i+j],dp[i][k]+dp[k+1][i+j]+sum[i][k]*sum[k+1][i+j]);
            }
        }
    }
    cout<<dp[0][n-1]<<"\n";

    return 0;
}