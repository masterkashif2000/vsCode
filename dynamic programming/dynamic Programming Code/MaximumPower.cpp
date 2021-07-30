Problem Name : Maximum Power
Topic : DP
Difficulty : Hard
EXPLANATION
It is similar to Largest Sum Contiguous Subarray problem. The only thing to note here is, maximum product can also be obtained by minimum (negative) product ending with the previous element multiplied by this element. For example, in array {12, 2, -3, -5, -6, -2}, when we are at element -2, the maximum product is multiplication of, minimum product ending with -6 and -2.

Time Complexity : O(NN).
#include<bits/stdc++.h>
using namespace std;
#define int long long 

int MaxProductSubarray(vector<int> &a){
    int n=a.size();
    int ans=a[0];
    int minProduct=1,maxProduct=1;
    if(a[0]>0)maxProduct=a[0];
    else minProduct=a[0];
    ans=max(ans,maxProduct);
    bool flag=false;
    for(int i=1;i<n;i++){
        if(a[i]==0){
            minProduct=maxProduct=1;
            continue;
        }
        if(a[i]>0){
            maxProduct=maxProduct*a[i];
            minProduct=min(a[i],minProduct*a[i]);
            flag=1;
        }
        else{
            int t=maxProduct;
            maxProduct=max(minProduct*a[i],1LL);
            minProduct=t*a[i];
        }
        ans=max(ans,maxProduct);
    }
    if(maxProduct==1 and flag==0)return 0;
    return ans;
}

signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<MaxProductSubarray(a)<<endl;
    return 0;
}
Approach 2
/*input
8
10 1 2 -13 0 7 -18 2 
*/
#include <bits/stdc++.h>
using namespace std;

#define boost  ios_base::sync_with_stdio(false);
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define pii pair<ll, ll>
#define f(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define rf(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define ms(a,b) memset((a),(b),sizeof(a))
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

#define abs(x) ((x<0)?(-(x)):(x))
#define MAX 100005
#define inf LLONG_MAX
#define MIN INT_MIN

//typedef
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}
ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}

/*..................................................................................................................................*/
ll arr[MAX];
ll maxSubarrayProduct(ll *arr, ll n)
{
    // max positive product ending at the current position
    ll max_ending_here = 1LL;

    // min negative product ending at the current position
    ll min_ending_here = 1LL;

    // Initialize overall max product
    ll max_so_far = 1LL;

    /* Traverse through the array. Following values are
       maintained after the i'th iteration:
       max_ending_here is always 1 or some positive product
                       ending with arr[i]
       min_ending_here is always 1 or some negative product 
                       ending with arr[i] */
    for (int i = 0; i < n; i++)
    {
        /* If this element is positive, update max_ending_here. 
           Update min_ending_here only if min_ending_here is 
           negative */
        if (arr[i] > 0)
        {
            max_ending_here = max_ending_here*arr[i];
            min_ending_here = min (min_ending_here * arr[i], 1LL);
        }

        /* If this element is 0, then the maximum product 
           cannot end here, make both max_ending_here and 
           min_ending_here 0
           Assumption: Output is alway greater than or equal 
                       to 1. */
        else if (arr[i] == 0)
        {
            max_ending_here = 1LL;
            min_ending_here = 1LL;
        }

        /* If element is negative. This is tricky
           max_ending_here can either be 1 or positive. 
           min_ending_here can either be 1 or negative.
           next min_ending_here will always be prev. 
           max_ending_here * arr[i] next max_ending_here
           will be 1 if prev min_ending_here is 1, otherwise 
           next max_ending_here will be prev min_ending_here *
           arr[i] */
        else
        {
            ll temp = max_ending_here;
            max_ending_here = max (min_ending_here * arr[i], 1LL);
            min_ending_here = temp * arr[i];
        }

        // update max_so_far, if needed
        if (max_so_far <  max_ending_here)
          max_so_far  =  max_ending_here;
    }

    return max_so_far;
}

// Driver Program to test above function
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<maxSubarrayProduct(arr,n);
    return 0;
}
