At first look , this looks like a Greedy problem but it is clearly not so. This can clearly be observed in a simple testcase like
4
5 4 8 6
Clearly , we would need an optimal solution for this. At each instance we would need to consider two possibilities that we can pick the first as well as the last element of the remaining array. Both these possibilities give rise to two more possibilities depending on the other player. Since the second player plays optimally and try to minimise our score. So overall we have two possibilities at each instance.
For the first possibility , where we could pick the first element , the other player will pick the next element from the side that would minimise our total score.
Similarly , for the second possibility , where we can pick the last element , the other player would still pick the next element from the side that would minimise our total score.
We entertain both these cases and take the maximum result of the two and return that result.
We take two pointer variables , say ‘i’ and ‘j’ which each represent the starting and the ending point of the remaining array currently in consideration. We work till the two pointers cross each other.
We use dynammic programming to further optimise it.

Naive Approach
A simple approach could be to simply use recursion while considering all posibilities and taking their best.


// C++ Code for Naive approach
#define ll long long int
ll coins[40];
ll optimalGame(ll i,ll j){
    if(i > j){
        return 0;
    }

    // Consider both the possibilities. You can pick either the first or the last coin.
    // Since the opponent plays optimally , we would get the minimum of the remaining coins for each choice.
    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;

    // Pick the max of two as your final result
    ll ans = max(pickFirst,pickLast);

    return ans;
}

// Java Code for Naive approach
    static long[] arr;

    public static long optimalGame(int i, int j) {
        if (i > j) {
            return 0;
        }
        //  Consider both the possibilities. You can pick either the first or the last coin.
        //  Since the opponent plays optimally , we would get the minimum of the remaining coins for each choice.
        long pickFirst = arr[i] + Math.min(optimalGame(i + 2, j), optimalGame(i + 1, j - 1));
        long pickLast = arr[j] + Math.min(optimalGame(i, j - 2), optimalGame(i + 1, j - 1));

        // Pick the max of two as your final result
        long ans = Math.max(pickFirst, pickLast);

        return ans;
    }


Optimised Approach
We can easily prove that this problem can be solved using DP.
Optimal Substructure - It can be clearly inferred from the recursive solution that we are solving our current problem using the results we obtain from smaller subproblems.
Overlapping subproblems - At each call , we are calling optimalGame(i + 1, j - 1) twice. And this is just for one call. For multiple calls , there would be several such instances of recursive calls repeating i.e. overlapping subproblems.

We can use DP to optimally store our solutions. We use Top Down DP here using the above recursive code.


// C++ Code

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll coins[10005];
ll dp[5000][5000];

ll optimalGame(ll i,ll j){
    if(i > j){
        return 0;
    }
    if(i<5000 && j<5000){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
    }

    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;

    ll ans = max(pickFirst,pickLast);

    if(i<5000 && j<5000){
        dp[i][j] = ans ; 
    }

    return ans;
}


int main() {
    ll n;
    cin >> n;   

    for(ll i=0;i<n;i++){
        cin >> coins[i];
    }

    memset(dp,-1,sizeof(dp)) ;
    cout << optimalGame(0,n-1);

    return 0;
}



// Java Code 
// For Java , use the custom Reader class for fast input output or you will get a TLE

static long[] arr;      // Array containing the elements
static long[][] dp;    // dp array with all elements initialised to -1

public static long optimalGame(int i, int j) {
    if (i > j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }
     // Consider both the possibilities. You can pick either the first or the last coin.
    // Since the opponent plays optimally , we would get the minimum of the remaining coins for each choice.
    long pickFirst = arr[i] + Math.min(optimalGame(i + 2, j), optimalGame(i + 1, j - 1));
    long pickLast = arr[j] + Math.min(optimalGame(i, j - 2), optimalGame(i + 1, j - 1));

    // Pick the max of two as your final result
    long ans = Math.max(pickFirst, pickLast);

    dp[i][j] = ans;

    return ans;
}

public static void main(String[] args) throws IOException {
    Reader sc = new Reader();

    int n = sc.nextInt();
    arr = new long[n];
    for (int i = 0; i < n; i++) {
        arr[i] = sc.nextLong();
    }

    dp = new long[10005][10005];
    for (int i = 0; i < dp.length; i++) {
        Arrays.fill(dp[i], -1);
    }

    System.out.println(optimalGame(0, n - 1));
}