#include <bits/stdc++.h>
#define MAX_N 1000000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int N, k;
int a[MAX_N];
ll f[MAX_N], backward[MAX_N];
ll maxScore;

inline ll max(ll x, ll y) { return (x > y) ? x : y; }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif
     cin >> N;
     cin >> k;
     k--;
     for (int i = 0; i < N; i++) cin >> a[i];

     backward[0] = 0;
     backward[1] = a[0];
     for (int i = 2; i < N; i++) {
          backward[i] = max(a[i - 2] + backward[i - 2], a[i - 1] + backward[i - 1]);
     }

     f[k] = 0;
     f[k + 1] = a[k + 1];
     for (int i = k + 2; i < N; i++) {
          f[i] = a[i] + max(f[i - 1], f[i - 2]);
     }

     maxScore = backward[k] + f[k];
     for (int i = k + 1; i < N; i++) {
          maxScore = max(maxScore, backward[i] + f[i]);
     }

     cout << maxScore << endl;
}

