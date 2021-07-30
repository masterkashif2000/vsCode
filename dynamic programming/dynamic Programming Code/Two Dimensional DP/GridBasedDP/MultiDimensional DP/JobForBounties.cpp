#include<bits/stdc++.h>
#define mod 1000000007
#define pp pair<ll,ll>
#define mp make_pair
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;

ll T,n,reward[110],deadline[110],duration[110],dp[1010][110];

int main(){
//    freopen("input1.txt","r",stdin);
//    freopen("output1.txt","w",stdout);
    ios::sync_with_stdio(0);

    cin>>T>>n;
    for(int i=1;i<=n;i++)
        cin>>reward[i];
    for(int i=1;i<=n;i++)
        cin>>duration[i];
    for(int i=1;i<=n;i++)
        cin>>deadline[i];

    for(int i=0;i<=T;i++)
        dp[i][0] = 0;
    for(int j=1;j<=n;j++)
        dp[0][j] = 0;

    ll ans = 0;
    for(int i=1;i<=T;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);//case where the job is not done
            if(duration[j] <= i && deadline[j] >= i){//condition for chosing jth job
                dp[i][j] = max(dp[i][j], reward[j]+dp[i-duration[j]][j-1]);//case where the jth job is chosen to be done
                ans = max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans;

    return 0;
}

