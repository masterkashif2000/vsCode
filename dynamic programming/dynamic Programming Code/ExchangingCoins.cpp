From the problem definition, say f (n) = ways to compute the change.

f (n) = max (n, f (n / 2) + f (n / 3) + f (n / 4)) (by definition).
f (0) = 0 (Base case)
Writing a simple recursive solution will time out due to exponential complexity i.e. O (3n ).
Writing a linear dynamic programming solution using arrays will exceed memory limit since N can be 109 in worst case.
To circumvent both of the a aforementioned problem, we can use maps and memoization.

Note: This is one of those problems where state space is extra large and memoization only explores space what is needed unlike bottom up dynamic programming which needs one to visit all the state space, memoization is the preferred solution in this case.


#include <cassert>
#include <cctype>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#include <fstream>
#include <iostream>
#include <sstream>

#include <ext/numeric>

using namespace std;
using namespace __gnu_cxx;

typedef long long int64;
const int INF = 0x3f3f3f3f;
template <class T> inline int len (const T &a) { return a.size (); }

#define MAXN 50
char line [MAXN];
map <int, int64> memo;

int64 solve (int n) {
    if (n == 0 || n == 1) return n;
    if (memo.count (n)) return memo [n];
    int64 ret = n;
    ret = max (ret, solve (n / 2) + solve (n / 3) + solve (n / 4));
    return memo [n] = ret;
}

int main () {
#ifdef LOCALHOST
    freopen ("test.in", "r", stdin);
    // freopen ("test.out", "w", stdout);
#endif

    int N;
         sscanf (line, "%d", &N);
        int64 ret = solve (N);
        printf ("%lld\n", ret);


    return 0;
}
💡 Exchanging Coins