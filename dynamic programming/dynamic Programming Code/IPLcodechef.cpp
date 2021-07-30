#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int dp[n+1];
	dp[0] = a[0];
	if(n>1)
	dp[1] = a[0]+a[1];
	if(n>2)
	dp[2] = max(dp[1], max(a[2]+a[0],a[2]+a[1]));
	for(int i=3;i<n;i++)
	dp[i] = max(dp[i-1],max(a[i]+a[i-1]+dp[i-3], a[i]+dp[i-2]));
	cout<<dp[n-1]<<endl;
	return 0;
}
