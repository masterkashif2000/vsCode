#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>graph(100005);
vector<int>degree(100005);
vector<int>dp(100005);

int32_t main(){
     //freopen("input.txt",  "r",  stdin);
     //freopen("output.txt", "w", stdout);
    int n,m;cin>>n>>m;

    //CONTAINERS ARE DECLARED GLOBALLY

    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        degree[b]++;
    }
    //BASIC TOPOLOGICAL SORT
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto x:graph[cur]){
            dp[x]=max(dp[x],dp[cur]+1);
            //BEST PATH CAN BE FROM ANY OTHER PATH OR MOVING THROUGH CUR
            //DP ENSURES LONGEST PATH TO REACH A NODE
            degree[x]--;
            if(degree[x]==0){
                q.push(x);
            }
        }
    }
    int ans=0;

    for(auto a:dp){
        ans=max(ans,a);
    }

    cout<<ans;

}