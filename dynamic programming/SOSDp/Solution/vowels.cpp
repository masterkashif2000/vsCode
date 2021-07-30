#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define V vector
#define pb push_back

const int N = (1 << 24), M = 24;
const int K = (1 << 24) - 1;

int dp[N];


int32_t main()
{
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, sum = 0, cnt = 0;
        cin >> n;
        for (i = 0; i < n; i++) {
            string s;
            cin >> s;
            int mask = 0;
            mask |= (1 << (s[0] - 'a'));
            mask |= (1 << (s[1] - 'a'));
            mask |= (1 << (s[2] - 'a'));
            dp[mask]++;
        }
        for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                if ((1 << i)&j) {
                    dp[j] += dp[(1 << i)^j];
                }
            }
        }
        for (i = 1; i < N; i++) {
            cnt = n - (dp[K ^ i]);
            cnt = cnt * cnt;
            ans ^= cnt;
        }
        cout << ans;
    }
}