Problem Name : LCS with 3 Strings
Topic : DP
Difficulty : Hard
EXPLANATION
This problem is simply an extension of LCS

Let the input sequences be X[0..m-1], Y[0..n-1] and Z[0..o-1] of lengths m, n and o respectively. And let L(X[0..m-1], Y[0..n-1], Z[0..o-1]) be the lengths of LCS of the three sequences X, Y and Z. Following is the implementation:

The idea is to take a 3D array to store the length of common subsequence in all 3 given sequences i. e., L[m + 1][n + 1][o + 1]

1- If any of the string is empty then there is no common subsequence at all then L[i][j][k] = 0

2- If the characters of all sequences match (or X[i] == Y[j] ==Z[k]) then L[i][j][k] = 1 + L[i-1][j-1][k-1]

3- If the characters of both sequences do not match (or X[i] != Y[j] || X[i] != Z[k] || Y[j] !=Z[k]) then L[i][j][k] = max(L[i-1][j][k], L[i][j-1][k], L[i][j][k-1])

Time Complexity : O($$ABC$$).
#include<bits/stdc++.h> 
using namespace std; 

int lcsOf3( string X, string Y, string Z, int m, 
                            int n, int o) 
{ 
    int L[m+1][n+1][o+1]; 

    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            for (int k=0; k<=o; k++) 
            { 
                if (i == 0 || j == 0||k==0) 
                    L[i][j][k] = 0; 

                else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1]) 
                    L[i][j][k] = L[i-1][j-1][k-1] + 1; 

                else
                    L[i][j][k] = max(max(L[i-1][j][k], 
                                        L[i][j-1][k]), 
                                    L[i][j][k-1]); 
            } 
        } 
    } 

    return L[m][n][o]; 
} 

int main() 
{ 
    string a,b,c;
    cin>>a>>b>>c;
  int m = a.length(); 
    int n = b.length(); 
    int o = c.length(); 
    cout <<lcsOf3(a,b,c, m, n, o); 

    return 0; 
} 
Another approach
The idea is to take a 3D dp to store the length of common subsequence in all 3 given sequences .

If any of the string is empty then there is no common subsequence at all then dp[i][j][k] = 0
If the characters of all sequences match (or X[i] == Y[j] ==Z[k]) then dp[i][j][k] = 1 + dp[i-1][j-1][k-1]
If the characters of both sequences do not match (or X[i] != Y[j] || X[i] != Z[k] || Y[j] !=Z[k]) then L[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1])

// Java Code 
public static int lcs(String str1, String str2, String str3) {
        int[][][] dp = new int[str1.length()+1][str2.length()+1][str3.length()+1];
        for(int i=1;i<=str1.length();i++) {
            for(int j=1;j<=str2.length();j++) {
                for(int k=1;k<=str3.length();k++) {
                    if(i==0 || j==0 || k==0)
                        dp[i][j][k]=0;
                    else if (str1.charAt(i-1)==str2.charAt(j-1) && str2.charAt(j-1)==str3.charAt(k-1))
                        dp[i][j][k]=1+dp[i-1][j-1][k-1];
                    else 
                        dp[i][j][k]=Math.max(dp[i-1][j][k], Math.max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
        return dp[str1.length()][str2.length()][str3.length()];
    }


// C++ Code 
int lcsOf3strings(string a,string b,string c){
    int dp[205][205][205];
    int m = a.size();
    int n = b.size();
    int p = c.size();

    for (int i=0; i<=m; i++)    {
        for (int j=0; j<=n; j++)        {
            for (int k=0; k<=p; k++)            {
                if (i == 0 || j == 0|| k == 0){
                    dp[i][j][k] = 0;
                }
                else if (a[i-1] == b[j-1] && a[i-1] == c[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                }
                else
                    dp[i][j][k] = max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
            }
        }
    }

    return dp[m][n][p];
}