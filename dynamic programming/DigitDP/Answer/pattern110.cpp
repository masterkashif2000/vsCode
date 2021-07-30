#include "bits/stdc++.h"
using namespace std;
const int N = 70;

int base[N];
int idx;

long long dp[N][2][2][2][2];

void make(long long x) {
     idx = 0;
     do {
          base[++idx] = (x & 1);
          x /= 2;
     } while (x > 0);
     while (idx < 66) base[++idx] = 0;
     reverse(base + 1 , base + 1 + idx);
}

bool yes(bool a , bool b , bool c) {
     return a && b && !c;
}

long long solve(int pos , bool lo , bool yet , bool prev , bool pre_prev) {
     if (pos > idx) {
          return yet;
     }
     if (dp[pos][lo][yet][prev][pre_prev] != -1)
          return dp[pos][lo][yet][prev][pre_prev];

     long long ret = 0;
     int to = lo ? 1 : base[pos];

     for (int cur = 0; cur <= to; ++cur) {
          ret += solve(pos + 1 , lo | (cur < base[pos]) , yet | yes(pre_prev, prev, cur), cur , prev);
     }
     return dp[pos][lo][yet][prev][pre_prev] = ret;
}

long long get(long long x) {
     if (!x) return 0;
     make(x);
     memset(dp , -1 , sizeof dp);
     return solve(1 , 0 , 0 , 0 , 0);
}

int main()
{
#ifndef ONLINE_JUDGE
     freopen("input2.txt",  "r",  stdin);
     freopen("output2.txt", "w", stdout);
#endif
     int tt;
     scanf("%d" , &tt);
     while (tt--) {
          long long l , r;
          scanf("%lld %lld", &l, &r);
          printf("%lld\n" , get(r) - get(l - 1));
     }
     return 0;
}