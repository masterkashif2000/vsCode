#include<bits/stdc++.h>
using namespace std;
// #define tez ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
signed main(){
    
    // tez
    int T=1;
    while(T--){
        int N;  cin>>N;
        int A[N][2];
        for(int i=0;i<N;i++)    cin>>A[i][0]>>A[i][1];
        int dp[N][2]={0};
        
        //dp[i][0] stores the count of all possible even sum combinations up until index i
        //dp[i][1] stores the count of all possible odd sum combinations up until index i    
        
        if(A[0][0]%2==1)    dp[0][1]++; else dp[0][0]++;
        if(A[0][1]%2==1)    dp[0][1]++; else dp[0][0]++;// initialising the array according to the first element
        
        for(int i=1;i<N;i++){
            for(int j=0;j<2;j++){
                if(A[i][j]%2==0)    dp[i][0]=(dp[i][0]+dp[i-1][0])%mod,dp[i][1]=(dp[i][1]+dp[i-1][1])%mod;
                // if the element is even then the dp[i][0] and dp[i][1] are exactly the same as upto index i-1
                else if(A[i][j]%2==1)   dp[i][0]=(dp[i][0]+dp[i-1][1])%mod,dp[i][1]=(dp[i][1]+dp[i-1][0])%mod;
                // if the element is odd then the counts interchange
            }
        }
        cout<<dp[N-1][1]<<endl;
    }
}