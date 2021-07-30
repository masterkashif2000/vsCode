Approach Discussion
At first look , this looks like a Greedy problem but it is clearly not so. This can clearly be observed in a simple testcase like
4
5 4 8 6
Clearly , we would need an optimal solution for this. At each instance we would need to consider two possibilities that we can pick the first as well as the last element of the remaining array. Both these possibilities give rise to two more possibilities depending on the other player. Since the second player plays optimally and try to minimise our score. So overall we have two possibilities at each instance.
For the first possibility , where we could pick the first element , the other player will pick the next element from the side that would minimise our total score.
Similarly , for the second possibility , where we can pick the last element , the other player would still pick the next element from the side that would minimise our total score.
We entertain both these cases and take the maximum result of the two and return that result.
We take two pointer variables , say ‘i’ and ‘j’ which each represent the starting and the ending point of the remaining array currently in consideration. We work till the two pointers cross each other.

C++ Code

#include <bits/stdc++.h>
using namespace std;

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


int main() {
    int n;
    cin >> n;   

    for(int i=0;i<n;i++){
        cin >> coins[i];
    }

    cout << optimalGame(0,n-1);

    return 0;
}


Java Code

import java.util.Scanner;

public class Main {

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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLong();
        }

        System.out.println(optimalGame(0, n - 1));

    }
}