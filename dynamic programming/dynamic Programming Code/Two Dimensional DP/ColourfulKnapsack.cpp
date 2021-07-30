Problem Name : Colorful Knapsack
Topic : DP
Difficulty : Hard
EXPLANATION
compute dp(i,j) for i ranging from 1 to m and j ranging from 1 to W. It indicates a boolean value implying whether it is possible to achieve weight j such that exactly one element from first i colored objects are taken. Ans = W — imax where imax is the maximum i such that dp(m, i) is true.

Time Complexity : O(M*XM∗X).
#include <bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> color;
int ans;
int dp[101][10001];

int f(int pos,int x){
    int &res=dp[pos][x];
    if(res!=-1)return res;
    res=0;

    if(pos>color.size()){
        ans=min(ans,x);
        return 0;
    }
    for(auto it:color[pos])
    {
        if(x>=it)
            res=max(res,f(pos+1,x-it));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);cout.tie(0);
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof dp);
    color.clear();
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        color[y].push_back(a[i]);
    }
    ans=INT_MAX;
    for(auto it:color)sort(it.second.begin(),it.second.end());
    int xx=f(1,x);
    if(ans==INT_MAX){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;

    return 0;
}