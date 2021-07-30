Problem Name : Job for Bounties
Topic : DP
Difficulty : Hard
EXPLANATION
A Simple Approach is to find all the substrings of given string. For every string, check if it is a valid string or not. If valid and length is more than maximum length so far, then update maximum length. We can check whether a substring is valid or not in linear time using a stack (See this for details). Time complexity of this solution is O(n2.

An Efficient Solution can solve this problem in O(n) time. The idea is to store indexes of previous starting brackets in a stack. The first element of stack is a special element that provides index before beginning of valid substring (base for next valid string).

1) Create an empty stack and push -1 to it. The first element of stack is used to provide base for next valid string.

2) Initialize result as 0.

3) If the character is '(' i.e. str[i] == '('), push index 'i' to the stack.

2) Else (if the character is ')') a) Pop an item from stack (Most of the time an opening bracket) b) If stack is not empty, then find length of current valid substring by taking difference between current index and top of the stack. If current length is more than result, then update the result. c) If stack is empty, push current index as base for next valid substring.

3) Return result.

Time Complexity : O(NN).
#include<bits/stdc++.h>
using namespace std;
#define int long long 


signed main(){
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    stack<int> st;
    st.push(-1);
    for(int i=0;i<n;i++){
        if(st.empty() || s[i]=='(')st.push(i);
        else{
            st.pop();
            ans=max(ans,i-st.top());
            if(st.empty())st.push
        }
    }
    cout<<ans<<endl;
    return 0;
}
Approach 2
#include<bits/stdc++.h>
#define mod 1000000007
#define pp pair<ll,ll>
#define mp make_pair
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;

int main(){
//    freopen("input2.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);

    string str;
    stack<int> stck;
    int dp[100010] = {0},ans=0;
    //dp[i] stores the length of longest valid substring if it teerminates at ith position

    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i] == '(')
            stck.push(i);
        else if(!stck.empty()){
            dp[i] = i-stck.top()+1;//length of open and close bracket pair
            if(stck.top() > 0)
                dp[i] += dp[stck.top()-1];//add length of previous valid substrings
            ans = max(ans,dp[i]);//update ans if value of dp[i] is more than ans
            stck.pop();//pop '(' from stack
        }
    }

    cout<<ans;

    return 0;
}