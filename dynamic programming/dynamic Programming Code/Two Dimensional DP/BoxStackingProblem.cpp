Problem Name : Box Stacking Problem
Topic : DP
Difficulty : Hard
EXPLANATION
Following are the key points to note in the problem statement: 1) A box can be placed on top of another box only if both width and depth of the upper placed box are smaller than width and depth of the lower box respectively. 2) We can rotate boxes such that width is smaller than depth. For example, if there is a box with dimensions {1x2x3} where 1 is height, 2×3 is base, then there can be three possibilities, {1x2x3}, {2x1x3} and {3x1x2} 3) We can use multiple instances of boxes. What it means is, we can have two different rotations of a box as part of our maximum height stack.

Following is the solution based on DP solution of LIS problem.

1) Generate all 3 rotations of all boxes. The size of rotation array becomes 3 times the size of original array. For simplicity, we consider depth as always smaller than or equal to width.

2) Sort the above generated 3n boxes in decreasing order of base area.

3) After sorting the boxes, the problem is same as LIS with following optimal substructure property. MSH(i) = Maximum possible Stack Height with box i at top of stack MSH(i) = { Max ( MSH(j) ) + height(i) } where j < i and width(j) > width(i) and depth(j) > depth(i). If there is no such j then MSH(i) = height(i)

4) To get overall maximum height, we return max(MSH(i)) where 0 < i < n

Following is the implementation of the above solution.

Time Complexity : O(N*NN∗N).
#include<bits/stdc++.h>
using namespace std;

struct Box 
{ 
  int h, w, d;  
};

int compare (const void *a, const void * b) 
{ 
    return ( (*(Box *)b).d * (*(Box *)b).w ) - 
           ( (*(Box *)a).d * (*(Box *)a).w ); 
} 

int BoxStackingProblem(vector<Box> &arr,int n){
    Box rot[3*n]; 
   int index = 0; 
   for (int i = 0; i < n; i++) 
   { 
      // Copy the original box 
      rot[index].h = arr[i].h; 
      rot[index].d = max(arr[i].d, arr[i].w); 
      rot[index].w = min(arr[i].d, arr[i].w); 
      index++; 

      // First rotation of box 
      rot[index].h = arr[i].w; 
      rot[index].d = max(arr[i].h, arr[i].d); 
      rot[index].w = min(arr[i].h, arr[i].d); 
      index++; 

      // Second rotation of box 
      rot[index].h = arr[i].d; 
      rot[index].d = max(arr[i].h, arr[i].w); 
      rot[index].w = min(arr[i].h, arr[i].w); 
      index++; 
   } 

   // Now the number of boxes is 3n 
   n = 3*n; 

   qsort (rot, n, sizeof(rot[0]), compare); 

   int msh[n]; 
   for (int i = 0; i < n; i++ ) 
      msh[i] = rot[i].h; 
   for (int i = 1; i < n; i++ ) 
      for (int j = 0; j < i; j++ ) 
         if ( rot[i].w < rot[j].w && 
              rot[i].d < rot[j].d && 
              msh[i] < msh[j] + rot[i].h 
            ) 
         { 
              msh[i] = msh[j] + rot[i].h; 
         } 


   int max = -1; 
   for ( int i = 0; i < n; i++ ) 
      if ( max < msh[i] ) 
         max = msh[i]; 

   return max; 
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<Box> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].h>>a[i].w>>a[i].d;
        }
        cout<<BoxStackingProblem(a,n)<<endl;
    }
}
// Approach 2

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

vector<pair<ll,pll>> dims;
vector<ll> maxHtPossibleWithIthBoxAtTop;
vector<vector<ll>>adj;
vector<bool>vis;

void dfs(ll i){
    vis[i]=true;

    ll ans=dims[i].first;
    for(ll j=0;j<adj[i].size();j++){
        if(!vis[adj[i][j]])dfs(adj[i][j]);
        ans=max(ans,maxHtPossibleWithIthBoxAtTop[adj[i][j]]+dims[i].first);
    }
    maxHtPossibleWithIthBoxAtTop[i]=ans;
}

int main()
{
    // freopen("input.txt","r",stdin);
     // freopen("output.txt","w",stdout);
    ll t=1;
    s(t);
    while(t--){
        ll n;
        s(n);
        dims.clear();
        maxHtPossibleWithIthBoxAtTop.clear();
        adj.clear();
        vis.clear();

        F(i,0,n-1){
            ll h,w,b;
            vector<ll>temp;
            s3(h,w,b);
            temp.pb(h);temp.pb(w);temp.pb(b);
            sort(temp.begin(), temp.end());
            h=temp[0];
            w=temp[1];
            b=temp[2];
            dims.push_back({h,{w,b}});
            dims.push_back({w,{h,b}});
            dims.push_back({b,{h,w}});
        }

        adj.resize(dims.size());
        vis.resize(dims.size());
        maxHtPossibleWithIthBoxAtTop.resize(dims.size());

        for(ll i=0;i<dims.size();i++){
            for(ll j=0;j<dims.size();j++){
                if(i==j)continue;
                if(dims[i].second.first<dims[j].second.first){
                    if(dims[i].second.second<dims[j].second.second)
                        adj[i].push_back(j);
                }
            }
        }

        for(ll i=0;i<dims.size();i++){
            if(vis[i])continue;
            dfs(i);
        }

        ll ans=0;
        for(ll i=0;i<maxHtPossibleWithIthBoxAtTop.size();i++)
            ans=max(ans,maxHtPossibleWithIthBoxAtTop[i]);

        p(ans);
    }
}