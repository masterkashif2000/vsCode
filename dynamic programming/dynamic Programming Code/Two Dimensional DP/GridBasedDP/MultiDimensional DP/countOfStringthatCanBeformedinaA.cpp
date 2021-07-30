C++ Code

#include <bits/stdc++.h>
using namespace std;

int countStrUtil(int dp[][2][3], int n, int bCount = 1, int cCount = 2)
{
    // Base cases
    if (bCount < 0 || cCount < 0)
        return 0;
    if (n == 0)
        return 1;
    if (bCount == 0 && cCount == 0)
        return 1;

    // if we had saw this combination previously
    if (dp[n][bCount][cCount] != -1)
        return dp[n][bCount][cCount];

    int res = countStrUtil(dp, n - 1, bCount, cCount);
    res += countStrUtil(dp, n - 1, bCount - 1, cCount);
    res += countStrUtil(dp, n - 1, bCount, cCount - 1);

    return (dp[n][bCount][cCount] = res);
}


int countStr(int n)
{
    int dp[n + 1][2][3];
    memset(dp, -1, sizeof(dp));
    return countStrUtil(dp, n);
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        cout << countStr(n) << endl;
    }

    return 0;
}

Java Code

import java.util.*;

/**
 * Main
 */
public class Main {

    static int countStrUtil(int dp[][][], int n, int bCount, int cCount) {
        // Base cases
        if (bCount < 0 || cCount < 0)
            return 0;
        if (n == 0)
            return 1;
        if (bCount == 0 && cCount == 0)
            return 1;

        // if we had saw this combination previously
        if (dp[n][bCount][cCount] != -1)
            return dp[n][bCount][cCount];

        int res = countStrUtil(dp, n - 1, bCount, cCount);
        res += countStrUtil(dp, n - 1, bCount - 1, cCount);
        res += countStrUtil(dp, n - 1, bCount, cCount - 1);

        return (dp[n][bCount][cCount] = res);
    }

    static int countStr(int n) {
        int[][][] dp = new int[n + 1][2][3];
        for (int i = 0; i < dp.length; i++) {
            dp[i][0][0] = dp[i][0][1] = dp[i][0][2] = -1;
            dp[i][1][0] = dp[i][1][1] = dp[i][1][2] = -1;
        }
        return countStrUtil(dp, n, 1, 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int testCases = sc.nextInt();
        while (testCases-- > 0) {
            int n = sc.nextInt();
            System.out.println(countStr(n));
        }

    }
}