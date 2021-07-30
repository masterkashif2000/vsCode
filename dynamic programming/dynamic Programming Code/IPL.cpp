#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<ll,ll>> vpll;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int n;
    cin>>n;
    vector<ll>v(n);
    ll ans=0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        ans += v[i];
    }
    
    ll dp[n]={0};
    dp[0]=v[0];
    dp[1]=v[1];
    dp[2]=v[2];
    for(int i=3; i<n; i++){
        dp[i] = min(dp[i-1], min(dp[i-2], dp[i-3]))+v[i];
    }
    ll ans2;
    ans2 = min(dp[n-1], min(dp[n-2], dp[n-3]));
    ans = ans-ans2;
    //cout<<ans2<<endl;
    cout<<ans<<endl;
	return 0;
}
