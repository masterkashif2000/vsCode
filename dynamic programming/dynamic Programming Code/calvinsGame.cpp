#include        "algorithm"
#include        "iostream"
#include        "numeric"
#include        "iomanip"
#include        "cstring"
#include        "math.h"
#include        "bitset"
#include        "string"
#include        "vector"
#include        "ctime"
#include        "queue"
#include        "stack"
#include        "map"
#include        "set"

#include        "ext/pb_ds/assoc_container.hpp" // Common file
#include        "ext/pb_ds/tree_policy.hpp" // Including tree_order_statistics_node_update
#include        "ext/pb_ds/detail/standard_policies.hpp"

using namespace std;
using namespace __gnu_pbds;


#define          f first
#define          lgn 25
#define          endl '\n'
#define          sc second
#define          pb push_back
#define          N (int)2e6+5
#define          PI acos(-1.0)
#define          int long long 
#define          vi vector<int>
#define          mod 1000000007
#define          ld long double
#define          eb emplace_back
#define          mii map<int,int>
#define          vpii vector<pii>
#define          pii pair<int,int>
#define          pq priority_queue
#define          BLOCK (int)sqrt(N)
#define          test(x) while(x--)
#define          all(x) begin(x),end(x)
#define          allr(x) rbegin(x),rend(x)
#define          fo(i,a,n) for(int i=a;i<n;i++)
#define          rfo(i,n,a) for(int i=n;i>=a;i--)
#define          FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define          time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"
#define 		 bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > 
OS ;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k,q;
string s;
vi adj[N];
int a[N] , dpf[N] , dpb[N]; // dpf to make forward moves
							// dpb to make backward moves

void go()
{
	cin >> n >> k;
	fo(i,1,n+1) cin >> a[i];

	dpf[k] = 0;
	dpf[k+1] = a[k+1];

	fo(i,k+2,n+1)
	{
		if( i - k > 2 )
		{
			dpf[i] = max( dpf[i-1] + a[i] , dpf[i-2] + a[i] );
		}
		else dpf[i] = max({ a[i] , dpf[i-1] + a[i] , dpf[i-2] + a[i] });
	}

	dpb[n] = dpf[n];
	dpb[n-1] = max( dpb[n] + a[n-1] , dpf[n-1] );

	rfo(i,n-2,k)
	{
		dpb[i] = max({ dpf[i] , dpb[i+1] + a[i] , dpb[i+2] + a[i] });
	}

	rfo(i,k-1,1)
	{
		dpb[i] = max( dpb[i+1] + a[i] , dpb[i+2] + a[i] );
	}

	cout << dpb[1] << endl;
}

int32_t main()
{
	FAST;     
	int t=1; 
	// cin>>t;
	test(t) go();
}