#include <bits/stdc++.h>
using namespace std;
int n ;
int x=0 ;
map<pair<int,int>,int> m ;
vector<int> temp ;
void dfs(int start,int val,vector<int> &v1,vector<vector<int>> &graph,vector<int> &visited){
    visited[start]=1 ;
    if(v1[start-1]<val) {
        temp.push_back(start) ;
        return ;
    }
    x++ ;
    vector<int> t=graph[start] ;
    for(int i=0;i<t.size();i++){
        int x=t[i] ;
        if(visited[x]==1) continue ;
        visited[x]=1 ;
        int v=val ;
        v+=m[make_pair(start,t[i])] ;
        if(v<0) v=0 ;
        dfs(x,v,v1,graph,visited) ;
    }
}

int32_t main(){
    // #ifndef ONLINE_JUDGE
    //  freopen("input.txt",  "r",  stdin);
    //  freopen("output.txt", "w", stdout);
    // #endif
    cin>>n ;
     vector<vector<int>> graph(n+1) ;
     vector<int> visited(n+1) ;
     vector<int> v(n) ;
     for(int i=0;i<n;i++) cin>>v[i] ;
     for(int i=1;i<=n-1;i++){
         int u,p,c ; cin>>u>>p>>c ;
         graph[u].push_back(p) ;
         graph[p].push_back(u) ;
         m[make_pair(u,p)]=c ;
         m[make_pair(p,u)]=c ;
     }
     dfs(1,0,v,graph,visited) ;
     cout<<n-x<<endl ;


}