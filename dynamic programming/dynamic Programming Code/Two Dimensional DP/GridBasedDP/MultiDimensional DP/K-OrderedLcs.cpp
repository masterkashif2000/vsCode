As mentioned in the problem statement, given problem is quite similar to the standard LCS problem. We can have following dp state DP(n,m,k) = denotes LCS for first n number of first array, first m numbers of second array when we are allowed to change at max k numbers in first array.

Recursion look like this ->
DP(n,m,k) = max(DP(n-1,m,k), DP(n, m-1, k), DP(n-1, m-1, k-1)+1), if arr[n]!=arr[m]
DP(n,m,k) = max(DP(n-1,m,k), DP(n, m-1, k), DP(n-1, m-1, k)+1), if arr[n]==arr[m]
The total number of distinct states, hence are = n * m * k
Time complexity = O(n * m * k)


#include <iostream>
#define ll long long int
using namespace std;

ll dp[2005][2005][8];

ll korderedLCS(int *a, int *b, int n, int m, int i, int j, int k) {
    if(n == i or m == j) {
        return 0;
    }
    if(dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    ll res = 0;
    if(a[i] == b[j]) {
        res = 1 + korderedLCS(a, b, n, m, i+1, j+1, k);
    } else {
        if(k>0) {
            res = 1 + korderedLCS(a, b, n, m, i+1, j+1, k-1);
        }
        res = max(res, korderedLCS(a, b, n, m, i+1, j, k));
        res = max(res, korderedLCS(a, b, n, m, i, j+1, k));
    }
    dp[i][j][k] = res;
    return res;

}

int main(int argc, char const *argv[])
{

    int n, m, k;
    cin>>n>>m>>k;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    for(int i=0;i<2005;i++) {
        for(int j=0;j<2005;j++) {
            for(int m=0;m<8;m++) {
                dp[i][j][m] = -1;
            }
        }
    }
    cout<< korderedLCS(a, b, n, m, 0, 0, k);
    return 0;
}

Lang - Java

 public static long korderedLCS(int[] a, int[] b, int i, int j, int k, long[][][] dp) {
        if (a.length == i || b.length == j) {
            return 0;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        long res = 0;
        if (a[i] == b[j]) {
            res = 1 + korderedLCS(a, b, i + 1, j + 1, k, dp);
        } else {
            if (k > 0) {
                res = 1 + korderedLCS(a, b, i + 1, j + 1, k - 1, dp);
            }
            res = Math.max(res, korderedLCS(a, b, i + 1, j, k, dp));
            res = Math.max(res, korderedLCS(a, b, i, j + 1, k, dp));
        }
        dp[i][j][k] = res;
        return res;

    }