// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

// using namespace __gnu_pbds;
using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*template
<
     class key,
     class val = null_type,
     class comp = less<key>
     >
using ord_set = tree
                <
                key,
                val,
                comp,
                rb_tree_tag,
                tree_order_statistics_node_update
                >;
*/
const int N = 2e6 + 100;

int a[N];

signed main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
#ifndef ONLINE_JUDGE
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
#endif
     int n, k;
     cin >> n >> k;
     for (int i = 0; i < n; i++)
          cin >> a[i];
     int prev_best_sum = 0,
         prev_best_ind = -1e9,
         prev_sec_sum = 0;
     for (int i = 0; i < (n + k - 1) / k; i++)
     {
          int cur_best_sum = prev_best_sum,
              cur_best_ind = prev_best_ind,
              cur_sec_sum = prev_sec_sum;
          for (int j = i * k; j < (i + 1)*k; j++)
          {
               int sum = prev_sec_sum + a[j];
               if (j - prev_best_ind != k)
                    sum = prev_best_sum + a[j];
               if (sum > cur_best_sum)
                    cur_sec_sum = cur_best_sum,
                    cur_best_sum = sum,
                    cur_best_ind = j;
               else if (sum > cur_sec_sum)
                    cur_sec_sum = sum;
          }
          prev_best_sum = cur_best_sum,
          prev_best_ind = cur_best_ind,
          prev_sec_sum = cur_sec_sum;
     }
     cout << prev_best_sum << "\n";
}

