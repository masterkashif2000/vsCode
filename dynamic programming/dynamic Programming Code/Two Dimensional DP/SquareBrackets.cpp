Problem Name : Square Brackets
Topic : DP
Difficulty : Hard
EXPLANATION
This problem can be solved by dynamic programming.

Let count(i,j) be the number of valid ways of filling the first i positions such that there are j more brackets of type '[' than of type ']'. Valid ways would mean that it is the prefix of a matched bracket expression and that the locations at which we have enforced '[' brackets have been satisfied. It is easy to see that count(2N,0) is the final answer we need.

The base case of the DP is that count(1,1)=1. You have to fill the first position with a '[' bracket, and there is only way to do this. count(1,i)=0 for i>1.

The recurrence for i>1 is: count(i,0) = count(i-1,1) count(i,j) = count(i-1,j-1) + count(i-1,j+1) for j>0

If i is a location where we have enforced a '[' bracket, the recurrence changes to: count(i,0) = 0 count(i,j) = count(i-1,j-1) for j>0

Using these relations, count(2N,0) can be found in O(N²) time.

Time Complexity : O(N*NN∗N).
#include<bits/stdc++.h>
using namespace std;
#define N 205

 int f[N][N], n, k;
 bool h[N];

 int main()
 {
     int t, d;
     scanf("%d", &t);
     while(t--)
     {
         scanf("%d%d", &n, &k);
         memset(h, 0, sizeof h);
        memset(f, 0, sizeof f);
         f[0][0] = 1;
         for(int i = 1; i <= k; i++)
         {
             scanf("%d", &d);
             h[d] = 1;
         }
         for(int i = 1; i <= 2 * n; i++)
         {
             for(int j = 0; j <= 2 * n; j++)
             {
                if(h[i])
                 {   
                     if(j != 0)
                         f[i][j] = f[i-1][j-1];
                     else
                         f[i][j] =  0;
                 }
                 else
                 {
                     if(j != 0)
                         f[i][j] = f[i-1][j-1] + f[i-1][j+1];
                     else
                         f[i][j] = f[i-1][j+1];
                 }
             }
         }
         printf("%d\n", f[2*n][0]);
     }
     return 0;
}
Another Approach
This is a DP problem clearly. At first glance , one would think they would require 3 parameters for their recursive call – an index variable denoting the current position ( say pos ) , count of opening brackets that have been placed ( say ‘open’ ) and another one indicating the count of closing brackets that have been placed ( say ‘close’ ) . So at first glance , one would think that this is a 3-d DP problem. While it can be solved using 3-d DP , using a 2D DP would be much more simpler and more efficient. At any instance during our traversal , we can surely say that the number of closing brackets that have been placed can easily be found using the other variables . Since all we have our open and closing brackets , we can simply determine this simple relationship –
Close = pos – open
The no of closing brackets that have been placed would be equal to the difference of current index and no of open brackets placed. Since we can uniquely identify any state of DP using these 2 variables , we will be making a 2D DP only and using these parameters for our DP access.
We traverse over the an imaginary string starting from index 0 ( pos = 0 ) and traverse till N = 2*n . Initially at the beginning since there are no opening brackets in the string , we implement the count of open to 0 as well ( open = 0 ) . At each instance in our recursive call ,we check whether we have reached the end. If so we check whether the count of current open unpaired brackets is 0 or not. If there are more open brackets than closed , we return 0. If all brackets are balanced and open ==0 , we return 1.
Also , we see that we are given some indices that must have an opening bracket. Since the total length of the string will be no longer than 40 , we can make a Boolean array and mark these positions as true in this array. All other positions are marked as false. If we encounter this position , we have no choice but to place an opening bracket here. At all other positions we have to consider two possibilities and add their results – one where we place an opening bracket as our current position , another where we place a closing bracket.


#include <bits/stdc++.h>
using namespace std;

bool openIndex[50];
int dp[50][50];

//N in function is actually equal to 2*n of input
//pos indicates index
//open indicates the no of open brackets in current string

int N;

int squareBrackets(int pos = 0, int open = 0)
{
    if (open < 0)
    {
        return 0;
    }
    if (pos == N)
    {
        return (open == 0);
    }
    if (dp[pos][open] != -1)
    {
        return dp[pos][open];
    }
    int ans = 0;
    if (openIndex[pos])
    {
        return squareBrackets(pos + 1, open + 1);
    }
    ans = squareBrackets(pos + 1, open + 1) + squareBrackets(pos + 1, open - 1);

    dp[pos][open] = ans;

    return ans;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        N = n << 1;

        int k;
        cin >> k;

        memset(openIndex, 0, sizeof(openIndex));

        for (int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            openIndex[x - 1] = 1;
        }

        memset(dp, -1, sizeof(dp));

        cout << squareBrackets() << endl;
    }

    return 0;
}