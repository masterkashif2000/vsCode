Problem Name : Interesting Encoding
Topic : DP
Difficulty : Hard
EXPLANATION
Intuition: dp[i] represents the number of different encoding for s[i..n]. You can easily see, dp[i]=dp[i+1]+(num<=26?dp[i+2]:0) where num is the decimal representation formed by s[i],s[i+1].

Time Complexity : O(NN).
#include<bits/stdc++.h>
using namespace std;
#define int long long 

bool isValid(int n){
    return (n>=1 and n<=26);
}

int dp[5001];

int f(string &s,int pos){
    int &res=dp[pos];
    if(res!=-1)return res;
    if(pos==s.size()){
        return 1;
    }
    res=0;
    if(s[pos]=='0')return res=0;
    res=f(s,pos+1);
    if(isValid((s[pos]-'0')*10 + s[pos+1]-'0'))
        res+=f(s,pos+2);
    return res;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        memset(dp,-1,sizeof dp);
        cout<<f(s,0)<<endl;
    }
}
Approach 2
/*input
23432453543
24534563456
364354576
234345
1342
1222
11
22222
1
2
0
*/

#include <cstdio>
#include <cstring>
using namespace std;
int main(){
int L;
char d[5001];
long long dp[5001];
int t; scanf("%d",&t);
while(t--){
    scanf("%s",d);
    if(d[0]=='0') break;
    L = strlen(d);
    dp[0] = dp[1] = 1;
    for(int i = 2;i<=L;++i){
    dp[i] = 0;
    char c1 = d[i-2]-'0', c2 = d[i-1]-'0';
    if(c1==1 || (c1==2 && c2<=6)) dp[i] += dp[i-2];
    if(c2!=0) dp[i] += dp[i-1];
    }
    printf("%lld\n",dp[L]);
}
return 0;
}

