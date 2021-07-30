Problem Name : BRIDGES
Topic : DP
Difficulty : Hard
EXPLANATION
We are given N pairs of start-point and endpoint in which a bridge can be built from the starting point to the endpoint. Two bridges is said to cut each other iff they share a common point that is not endpoint. Find the maximum number of bridges can be built.

Solution: At first I thought this it is a knapsack problem and tried to solve it as follows: Firstly we need to sort the pairs such that the starting points are in increasing order. Let M(i, x) be the maximum number of bridges that can be built between [i .. N] such that the lowest coordinate of endpoint is x. Then M(i,x) = max {M(i+1, x) , 1 + M(i+1, endpoint[i] (if endpoint[i] >= x) )} The complexity of the algorithm is a pseudo polynomial O(N|M|) where N is the number of pairs, and M is the range of endpoints. Unfortunately this does not pass the time limit.

The better approach is to realize that the problem can be modeled as a longest increasing subsequence problem, where for each possible bridge, we check the maximum number of bridges can be built with the current bridge as the last one to be built. My implementation has an O(N2) complexity and it passed the time limit :D

I think you can further optimize this to an O(NlgN) LIS solution, might be worth the try.

Time Complexity : O(N*N), can be optimises to O(NLogN);
#include <algorithm>
#include <cstdio>
#include <utility>
#include <iostream>
using namespace std;
int st[1003], fin[1003];
pair<int, int> edge[1003];
int dp[1003][2003];
int lis[1003];
int N;
int ans;


void knapsack(){
    sort(edge, edge+N);
    ans = 0;
    for(int i=0;i<=2000;++i){
        dp[N][i] = 0;
    }
    for(int i=N-1;i>=0;--i){
        int cur = edge[i].second+1000;
        for(int x=2000;x>=0;--x){
            dp[i][x] = dp[i+1][x];
            if(x <= cur) dp[i][x] = max(dp[i][x], 1 + dp[i+1][cur]);
            ans = max(ans, dp[i][x]);
        }
    }
    printf("%d\n", ans);
}

void LIS(){
    sort(edge, edge+N);
    ans = 0;
    for(int i=0;i<N;++i){
        lis[i] = 1;
        for(int j=i-1;j>=0;--j){
            if(edge[j].second <= edge[i].second){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        ans = max(ans, lis[i]);
    }
    printf("%d\n", ans);
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &N);
        for(int i=0;i<N;++i){
            scanf("%d", &st[i]);
        }
        for(int i=0;i<N;++i){
            scanf("%d", &fin[i]);
        }
        for(int i=0;i<N;++i){
            edge[i] = make_pair(st[i], fin[i]);
        }
        LIS();
    }
    return 0;
}