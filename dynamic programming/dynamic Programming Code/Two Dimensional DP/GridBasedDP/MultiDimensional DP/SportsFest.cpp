#include<bits/stdc++.h>
#define mod 1000000007
#define pp pair<ll,ll>
#define mp make_pair
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;

ll dpC[100010],dpF[100010],dpH[100010],n;

int main(){
//    freopen("input4.txt","r",stdin);
//    freopen("output4.txt","w",stdout);
    ios::sync_with_stdio(0);

    cin>>n;

    // base cases
    dpC[1] = dpF[1] = dpH[1] = 1;
    dpH[2] = 2;

    for(int i=1;i<=n;i++){
        if(i-1 > 0){
            dpC[i] = (dpC[i-1] + dpF[i-1] + dpH[i-1]) % mod; // recurrence for cricket
            dpF[i] = (dpC[i-1] + dpH[i-1]) % mod; // recurrence for football
        }
        if(i-2 > 0){
            dpH[i] = (2*dpC[i-2] + dpF[i-2]) % mod; // recurrence for hockey
        }
    }

    cout<<(dpC[n] + dpF[n] + dpH[n]) % mod;

    return 0;
}