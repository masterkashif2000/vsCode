#include <bits/stdc++.h>
using namespace std;
int ans=0;
vector<vector<int>>graph(100005);
map<pair<int,int>,int>edge_length;
//STORES LENGTH OF AN EDGE CORRESPONDING TO ITS PAIR

int dfs(int cur, int par){
    vector<int>outcomes;
    for(auto a:graph[cur]){
        if(a!=par){
            outcomes.push_back(edge_length[{a,cur}]+dfs(a,cur));
            //ALL POSSIBLE LENGTHS STARTING FROM NODE CUR
        }
    }
    sort(outcomes.rbegin(),outcomes.rend());
    if(outcomes.size()>1)ans=max(ans,outcomes[0]+outcomes[1]);
    //NODE CUR COMES IN CENTRE
    if(outcomes.size()==1)ans=max(ans,outcomes[0]);
    //NODE CUR COMES IN EDGE
    if(outcomes.size()==0)return 0;
    return outcomes[0];
    //RETURNING LONGEST PATH
}
int32_t main(){
   // #ifndef ONLINE_JUDGE
   // freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
   // #endif
    //CONTAINERS ARE DECLARED GLOBALLY
    int n;cin>>n;

    for(int i=0;i<n-1;i++){
        int a,b,c;cin>>a>>b>>c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edge_length[{a,b}]=c;
        edge_length[{b,a}]=c;
    }
    dfs(1,0);

    cout<<ans;


}