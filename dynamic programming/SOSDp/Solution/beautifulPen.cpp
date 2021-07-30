#include "bits/stdc++.h"
using namespace std;

int  n, k;
int  pos[1 << 20];
char s[1 << 20];
char g[233];
#define lowbit(x) ((x)&(-(x)))

int main()
{
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    memset(pos, 0, sizeof pos);
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; ++i) {
      s[i] -= 'a';
    }
    for (int i = 0; i < k; ++i) {
      cin >> g;
      int l    = strlen(g);
      int mask = 0;
      for (int j = 0; j < l; ++j) {
        mask |= 1 << (g[j] - 'a');
      }
      pos[mask] = i + 1;
    }
    for (int z = (1 << 20); z > 0; --z) {
      if (pos[z]) {
        int c = z;
        while (c) {
          pos[z ^ lowbit(c)] = pos[z];
          c ^= lowbit(c);
        }
      }
    }
    int lst = 0;
    int msk = 0;
    for (int i = 0; i < n; ++i) {
      msk |= 1 << s[i];
      if (!pos[msk]) {
        int z = pos[msk ^ 1 << s[i]];
        for (int j = lst; j != i; ++j) {
          cout << z << ' ';
        }
        lst = i;
        msk = 1 << s[i];
      }
    }
    for (int i = lst; i < n; ++i) {
      cout << pos[msk] << ' ';
    }
    cout << '\n';
  }
  return 0;
}