#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int             long long int
#define ld              long double
#define lop(i, a, b)    for (int i = a; i < b; i++)
#define rlop(i, b, a)   for (int i = b-1; i >= a; i--)
#define F               first
#define S               second
#define pb              push_back
#define si              set <int>
#define vi              vector <int>
#define pii             pair <int, int>
#define vpi             vector <pii>
#define vpp             vector <pair<int, pii>>
#define mii             map <int, int>
#define mpi             map <pii, int>
#define spi             set <pii>
#define endl            "\n" 
#define sz(x)           ((int) x.size())
#define all(p)          p.begin(), p.end()
#define que_max         priority_queue <int>
#define que_min         priority_queue <int, vi, greater<int>>
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define mset(a, b, c)   lop (i, 0, c) a[i] = b
#define print1(a, n)    lop (i, 0, n) cout << a[i] << " "; cout << endl

inline int power(int a, int b)
{
     int x = 1;
     while (b)
     {
          if (b & 1) x *= a;
          a *= a;
          b >>= 1;
     }
     return x;
}

typedef tree<pii, null_type, less<pii>, rb_tree_tag,tree_order_statistics_node_update> Set;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

int cache[11][11][11][11];
string s,s1,s2;

int dp(int i,int cnt,int cnt1,int cnt2)
{
     if(i==0) return 0;

     int &ans=cache[i][cnt][cnt1][cnt2];
     if(ans!=-1) return ans;

     ans=0;

     if(cnt && (i-cnt1) && (i-cnt2)) ans=max(ans,power(2,i-1)+dp(i-1,cnt-1,cnt1,cnt2));
     if(cnt1 && (i-cnt) && (i-cnt2)) ans=max(ans,power(2,i-1)+dp(i-1,cnt,cnt1-1,cnt2));
     if(cnt2 && (i-cnt1) && (i-cnt)) ans=max(ans,power(2,i-1)+dp(i-1,cnt,cnt1,cnt2-1));

     if(cnt && cnt1 && (i-cnt2)) ans=max(ans,dp(i-1,cnt-1,cnt1-1,cnt2));
     if(cnt1 && cnt2 && (i-cnt)) ans=max(ans,dp(i-1,cnt,cnt1-1,cnt2-1));
     if(cnt && cnt2 && (i-cnt1)) ans=max(ans,dp(i-1,cnt-1,cnt1,cnt2-1));

     if(cnt && cnt1 && cnt2) ans=max(ans,power(2,i-1)+dp(i-1,cnt-1,cnt1-1,cnt2-1));

     if((i-cnt) && (i-cnt1) && (i-cnt2)) ans=max(ans,dp(i-1,cnt,cnt1,cnt2));

     return ans;

}

void solve()
{
     memset(cache,-1,sizeof(cache));
     cin>>s>>s1>>s2;

     int cnt=0,cnt1=0,cnt2=0;
     for(auto x:s)
          cnt+=(x=='1');

     for(auto x:s1)
          cnt1+=(x=='1');

     for(auto x:s2)
          cnt2+=(x=='1');

     int x=dp(10,cnt,cnt1,cnt2);

     if(!x)
     {
          cout<<"0000000000"<<endl;
          return ;
     }

     string ans;
     while(x)
     {
          if(x&1)
               ans+='1';
          else 
               ans+='0';
          x/=2;
     }
     reverse(all(ans));
     cout<<ans<<endl;

}

int32_t main()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
     freopen("input2.txt",  "r",  stdin);
     freopen("output2.txt", "w", stdout);
#endif

     int t; cin >> t;
     while (t--) solve();

     return 0;
}