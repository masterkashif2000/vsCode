#include<bits/stdc++.h>
using namespace std;

const int N = 1 << 20 | 5, P = 1e9 + 7;
int n, f[N], g[N], h[N], dp[N];

inline void read_input() {
    cin >> n;
    for (int i = 0; i < 1 << n; i++)
        cin >> f[i];
    for (int i = 0; i < 1 << n; i++)
        cin >> g[i];
    for (int i = 0; i < 1 << n; i++)
        cin >> h[i];
}

inline void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1 << n; j++)
            if (j >> i & 1) {
                (f[j] += f[j ^ (1 << i)]) %= P;
                (g[j] += g[j ^ (1 << i)]) %= P;
                (h[j] += h[j ^ (1 << i)]) %= P;
            }
    for (int i = 0; i < 1 << n; i++) {
        dp[i] = 1LL * f[i] * g[i] % P * h[i] % P;
        if (__builtin_popcount(i) & 1)
            dp[i] = P - dp[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1 << n; j++)
            if (j >> i & 1)
                (dp[j] += dp[j ^ (1 << i)]) %= P;
}

inline void write_output() {
    int ans = 0;
    for (int i = 0; i < 1 << n; i++) {
        int cnt = __builtin_popcount(i);
        if (cnt & 1)
            dp[i] = P - dp[i];
        (ans += (1LL << cnt) * dp[i] % P) %= P;
    }
    cout << ans;
}

int main() {
    ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    read_input(), solve(), write_output();
    return 0;
}