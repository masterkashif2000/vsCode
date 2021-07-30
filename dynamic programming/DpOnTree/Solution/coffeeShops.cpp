#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> graph(100005);
vector<int> visited(100005);
int ans=0;
vector<int> findans(int current_node,int k){
    visited[current_node]=1;
    vector<vector<int>> p;
    for(auto x:graph[current_node]){
        if(!visited[x]){
            p.push_back(findans(x,k));
        }
    }
    vector<int> dp(12);
    //dp[i] represents the number of nodes at distance i from the current node 
    //in its subtree 
    for(int i=0;i<12;i++){
        for(int j=0;j<p.size();j++){
            dp[i+1]+=p[j][i];
        }
    }
    dp[0]=1;
    int t=0;
    t+=dp[k]*2;//number of pairs starting from current vertex and ending at another
               //node in subtree
    for(int i=0;i<=k;i++){
        for(int j=0;j<p.size();j++){
            if(k-i-2>=0)
            t+=p[j][i]*(dp[k-1-i]-p[j][k-i-2]);
            //number of pairs starting and ending in the subtree
        }
    }
    ans+=t/2;
    return dp;
}
int32_t main(){
   // #ifndef ONLINE_JUDGE
     //freopen("input.txt",  "r",  stdin);
     //freopen("output.txt", "w", stdout);
    //#endif
    int n,k;
    cin>>n>>k;
    //containers are declared globally
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);graph[b].push_back(a);
    }
    //dfs starting from 1.Any node can be selected
    findans(1,k);
    cout<<ans;

}