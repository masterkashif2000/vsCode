#include<iostream>
using namespace std;

unsigned long int CatalanNumber(unsigned int n){
	unsigned long int dp[n+1];
	dp[0]=dp[1]=1;

	for(int i=2;i<=n;i++){
		dp[i]=0;
		for(int j=0;j<i;j++){
			dp[i]+=dp[j]*dp[i-j-1];
		}
	}
	return dp[n];
}

int main() {
	unsigned int n;
	cin>>n;
	cout<<CatalanNumber(n)<<endl;
}