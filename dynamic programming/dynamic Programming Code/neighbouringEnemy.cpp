Problem Name : Neighbouring Enemy
Topic : DP
Difficulty : Hard
EXPLANATION
This problem is similar to Alice and Bob. Let's consider a simple case to begin with, if the sequence is 2 2 2. Then, clearly, Alex has only one choice - to pick the number 2. In that case, his score would be 2*3 = 6.

Moving forward, if the sequence was 2 2 3. Then Alex has two choices - to choose 2, or 3. Now, on choosing 2, his score would be 22 = 4. But (2 + 1) = 3 would be eliminated from the sequence, so 4 will be his final score. On the other hand, if he chooses 3, his score would be 31 = 3, and yet again, (3 - 1) = 2 will be eliminated from the array. Clearly, the maximal score is 4.

As it is clearly visible, it is the frequency of the number appearing, as well as the number itself that is significant. Hence, we initiate an array, count[i], storing the number of times the element i appears in the sequence.

Hence for the above sequence 2 2 3, count[2] = 2, and count[3] = 3.

Finally, to find the optimal score, it would be easy to first break the problem down into smaller problem. In this case, we break the sequence into smaller sequence and find optimal solution for it.

For the sequence of number containing only 0, the answer would be 0. Similarly, if a sequence contains only the number 0 and 1, then the solution would be count[1]*1.

Now we are ready to build the recursive solution for this problem. For a sequence of number containing only the numbers, 0 to n, we can either pick the nth element, or not. Hence,

dp[i] = 
max(
dp[i - 1], // Not picking the ith number, then the number before it can be considered
dp[i - 2] + i*a[i] // Picking the ith number, then the number before it is eliminated, hence the number before that is considered
);

Once we have the recursive solution, it is quite easy to see, that for the complete sequence of numbers, ie, from 0 to 100000, the solution is simply, dp[100000].

Time Complexity : O(maxElementmaxElement).
#include<bits/stdc++.h>
using namespace std;
#define int long long 


signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    unordered_map<int,int> cnt;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    vector<int> dp((*max_element(a.begin(),a.end()))+1,0);
    for(int i=1;i<dp.size();i++){
        dp[i]=dp[i-1];
        if(1){
            dp[i]=max(dp[i],(i>=2?dp[i-2]:0)+cnt[i]*i);
        }
    }
    cout<<dp[dp.size()-1]<<endl;
    return 0;
}


Another Approach
// http://codeforces.com/contest/455/problem/A

// SPACE EFFICIENT APPROACH
// FOR EASIER BUT SPACE COSTLY APPROACH, LOOK FOR THE PREVIOUS SUBMISSION FOR THE SAME PROBLEM

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 #define fio ios_base::sync_with_stdio(false)

#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)

#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)

#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll n;
    s(n);
    vector<ll>b;
    map<ll,ll>mp;
    ll num;
    F(i,0,n-1){cin>>num; mp[num]++;}
    for(auto ele:mp){
      b.push_back(ele.first);
    }

    n=b.size();
    vector<ll>dp(n,0);
    dp[0]=b[0]*mp[b[0]];

    for(ll i=1;i<n;i++){
      if(b[i]==b[i-1]+1){
        ll temp = b[i]*mp[b[i]];
        if(i>=2) temp+=dp[i-2];
        dp[i]=max(dp[i-1],temp);
      }else dp[i]=dp[i-1]+b[i]*mp[b[i]];
    }
    cout<<dp[n-1]<<endl;
  }
}

// very basic thing to think, dp[i] = maximum sum possible till the ith number. 
// so we have only two possibilities, either we take the ith digit and delete it, or we take another digit , 1 less than
// the current digit, and delete that. we pick the maximum of the two.