#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int MAXN = 510;

int n, t;
long long dp[MAXN][MAXN], a[MAXN], sum[MAXN][MAXN], ans;

inline int mod(int x) {
     if (x < n)
          return x;
     if (x >= n)
          return x - n;
}

long long solve(int l, int r) {
     if (dp[l][r] != -1)
          return dp[l][r];
     if (l == r)
          return dp[l][r] = 0;
     if (mod(l + 1) == r)
          return dp[l][r] = a[l] + a[r];
     long long ret = INF;
     for (int i = l; i != r; i = mod(i + 1))
          ret = min(ret, solve(l, i) + solve(mod(i + 1), r) + sum[l][r]);
     return dp[l][r] = ret;
}

int main() {
     ios::sync_with_stdio(0);

     cin >> n;
     memset(dp, -1, sizeof dp);
     for (int i = 0; i < n; i++)
          cin >> a[i];
     ans = INF;
     for (int i = 0; i < n; i++) {
          sum[i][i] = a[i];
          for (int j = mod(i + 1); j != i; j = mod(j + 1)) {
               sum[i][j] = sum[i][mod(j + n - 1)] + a[j];
          }
     }
     for (int i = 0; i < n; i++) {
          ans = min(ans, solve(i, mod(i + n - 1)));
     }
     cout << ans << endl;

     return 0;
}