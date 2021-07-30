#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> graph(100005);
vector<int> degree(100005),statue(100005);
vector<vector<int>>dp(100005,vector<int>(21));
//21 because statues are 20
int32_t main(){
    //#ifndef ONLINE_JUDGE
     //freopen("input.txt",  "r",  stdin);
     //freopen("output.txt", "w", stdout);
    //#endif
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>statue[i];
    }
    for(int i=0;i<k;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
        degree[b]++;
    }
    // Basic Topological Sorting
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            q.push(i);
            dp[i][statue[i]]++;
        }
    }
    //dp[i][j] represents maximum statues of type j on reaching city i
    int count=0;
    while(!q.empty()){
        int k=q.front();
        q.pop();
        for(auto a:graph[k]){
            degree[a]--;
            for(int i=0;i<21;i++){
                dp[a][i]=max(dp[a][i],dp[k][i]);
                //maximum statues of any type on reaching a will also be maximum for k
            }
            dp[a][statue[a]]=max(dp[k][statue[a]]+1,dp[a][statue[a]]);
            //statue on city a will increment by one 
            if(degree[a]==0){
                q.push(a);
            }
        }
        count++;
    }
    if(count<n){
        cout<<-1;
        return 0;
    }
    int ans=0;
    for(auto a:dp){
        for(auto b:a){
            ans=max(ans,b);
        }
    }
    cout<<ans;