Approach
Each occurrence of ‘?’ character in wildcard pattern can be replaced with any other character and each occurrence of ‘*’ with a sequence of characters such that the wildcard pattern becomes identical to the input string after replacement.

Let’s consider any character in the pattern.

Case 1: The character is ‘*’ Here two cases arise

We can ignore ‘’ character and move to next character in the Pattern. ‘’ character matches with one or more characters in Text. Here we will move to next character in the string. Case 2: The character is ‘?’ We can ignore current character in Text and move to next character in the Pattern and Text.

Case 3: The character is not a wildcard character If current character in Text matches with current character in Pattern, we move to next character in the Pattern and Text. If they do not match, wildcard pattern and Text do not match.

We can use Dynamic Programming to solve this problem – Let T[i][j] is true if first i characters in given string matches the first j characters of pattern.

C++ Code
#include <bits/stdc++.h>
using namespace std;

bool wildcard(const string &text,const string &pattern){
    int r = text.size();
    int c = pattern.size();

    vector<vector<bool>>dp(r+1,vector<bool>(c+1));   //dp[i][j] denotes if the text till i and pattern till j match

    // for(int i=0;i<=r;i++){
    //     dp[i][0] = dp[0][i] = false  ;
    // }

    dp[0][0] = true ; //Base case - Strings of 0 length always match

    //If first character of pattern is * then mark (0,1) as true since * can be mapped with empty sequence as well
    if(pattern[0] == '*'){
        dp[0][1] = true ;
    }
    for(int i=0;i<pattern.size() and pattern[i]=='*';i++){
        dp[i][1] = true ; 
    }

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(text[i-1] == pattern[j-1]){
                //If current character of each string matches then mark this as however its previous state was
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[j-1] == '?'){
                //Since ? can be mapped with all characters , do the same for this as well
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[j-1] == '*'){
                //Since * can be mapped with all strings , mark current state as OR of both previous states
                dp[i][j] = dp[i-1][j] || dp[i][j-1] ; 
            }
            else {
                //Since no matching took place , mark this cell as false
                dp[i][j] = false ;
            }
        }
    }

    /*
    for(int i=0;i<=r;i++){
        for(int j=0;j<=c;j++){
            cout << dp[i][j] << " "; 
        }
        cout << endl ;
    }
    */


    return dp[r][c];
}

int main() {
    string a,b;
    cin >> a >> b;

    if(a==b){
        cout<<1;
        return 0;
    }

    //Remove consecutive * from the pattern string
    for(int i=0; i + 1 < b.size();i++){
        if(b[i] == '*' && b[i+1] == '*'){
            b.erase(i,1);
            i--;
        }
    }

   // cout << "b = "<< b <<endl;

    cout << wildcard(a,b);

    return 0;
}

Java Code

import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a, b;
        a = sc.next();
        b = sc.next();

        if (a.equals(b)) {
            System.out.println(1);
            return;
        }

        StringBuilder tmp = new StringBuilder(b);

        //Remove consecutive * from the pattern string
        for (int i = 0; i + 1 < tmp.length(); i++) {
            if (tmp.charAt(i) == '*' && tmp.charAt(i + 1) == '*') {
                tmp.deleteCharAt(i);
                i--;
            }
        }

        b = tmp.toString();

        int ans = wildcard(a, b) ? 1 : 0;
        System.out.println(ans);

    }

    static boolean wildcard(String text, String pattern) {
        int r = text.length();
        int c = pattern.length();

        boolean[][] dp = new boolean[r + 1][c + 1];

        for (int i = 0; i <= r; i++) {
            dp[i][0] = false;
        }

        for (int j = 0; j <= c; j++) {
            dp[0][j] = false;
        }

        dp[0][0] = true; //Base case - Strings of 0 length always match

        //If first character of pattern is * then mark (0,1) as true since * can be mapped with empty sequence as well
        if (pattern.charAt(0) == '*') {
            dp[0][1] = true;
        }
        for (int i = 0; i < pattern.length() && pattern.charAt(i) == '*'; i++) {
            dp[i][1] = true;
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (text.charAt(i - 1) == pattern.charAt(j - 1)) {
                    //If current character of each string matches then mark this as however its previous state was
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern.charAt(j - 1) == '?') {
                    //Since ? can be mapped with all characters , do the same for this as well
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern.charAt(j - 1) == '*') {
                    //Since * can be mapped with all strings , mark current state as OR of both previous states
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    //Since no matching took place , mark this cell as false
                    dp[i][j] = false;
                }
            }
        }



        return dp[r][c];
    }
}