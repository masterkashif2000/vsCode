#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long> a(n);
    for(auto &i : a)
        cin >> i;
    long maxSum = 0;
    vector<long> dp = a;
    for(int i = k; i < n; i += k) {
        int max_i = i - k, smax_i = -1;
        for(int j = i - k + 1; j < i; j++) {
            if(dp[j] > dp[max_i]) {
                smax_i = max_i;
                max_i = j;
            }
            else if(smax_i == -1 or dp[j] > dp[smax_i]) {
                smax_i = j;
            }
        }
        for(int j = i; j < i + k and j < n; j++) {
			if(a[j] < 0) dp[j] = dp[max_i];
            else if(j - max_i != k) dp[j] = a[j] + dp[max_i];
            else dp[j] = a[j] + dp[smax_i];
            maxSum = max(maxSum, dp[j]);
        }
    }
    cout << maxSum;
}