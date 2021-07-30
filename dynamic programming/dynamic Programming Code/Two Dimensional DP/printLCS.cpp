Problem Name : Print LCS
Topic : DP
Difficulty : Medium
EXPLANATION
Following is a detailed algorithm to print the LCS. It uses the same DP table that was calculated using count LCS program.

1) Construct dp[m+1][n+1] using the count LCS dynamic programming solution.

2) The value dp[m][n] contains length of LCS. Create a character array lcs[] of length equal to the length of lcs plus 1 (one extra to store \0).

3) Traverse the 2D array starting from dp[m][n]. Do following for every cell dp[i][j]

If characters (in X and Y) corresponding to dp[i][j] are same (Or X[i-1] == Y[j-1]), then include this character as part of LCS.
Else compare values of dp[i-1][j] and dp[i][j-1] and go in direction of greater value.
C++ Code for LCS

string lcs(string a,string b)
{
    int la=a.length();
    int lb=b.length();
    int dp[1001][1001] = {0};

    for(int i=0;i<=la;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=lb;i++)
    {
        dp[0][i]=0;
    }

    // Following steps build dp[m+1][n+1] in bottom up fashion. Note 
    // that dp[i][j] contains length of LCS of a[0..i-1] and b[0..j-1]
    for(int i=1;i<=la;i++)
    {
        for(int j=1;j<=lb;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=la,j=lb;
    string ans="";
    // Start from the right-most-bottom-most corner and 
    // one by one store characters in lcs[] 
    while(i>0 && j>0)
    {
        if(a[i-1] == b[j-1])
        {
            // If current character in a and b are same, then 
            // current character is part of LCS 
            ans=a[i-1]+ans;
            i--;
            j--;
        }
        // If not same, then find the larger of two and 
        // go in the direction of larger value
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return ans;
}
Java Code

import java.util.*;

class Main{
    static String lcs(String a,String b){
        int la = a.length();
        int lb = b.length();
        int [][]dp = new int[1001][1001];

        for(int i=0;i<=la;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=lb;i++)
        {
            dp[0][i]=0;
        }

        // Following steps build dp[m+1][n+1] in bottom up fashion. Note 
        // that dp[i][j] contains length of LCS of a[0..i-1] and b[0..j-1]
        for(int i=1;i<=la;i++)
        {
            for(int j=1;j<=lb;j++)
            {
                if(a.charAt(i-1)==b.charAt(j-1))
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=la,j=lb;
        String ans="";
        // Start from the right-most-bottom-most corner and 
        // one by one store characters in lcs[] 
        while(i>0 && j>0)
        {
            if(a.charAt(i-1)==b.charAt(j-1))
            {
                // If current character in a and b are same, then 
                // current character is part of LCS 
                ans=a.charAt(i-1)+ans;
                i--;
                j--;
            }
            // If not same, then find the larger of two and 
            // go in the direction of larger value
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        System.out.println(lcs(a,b));
    }
}