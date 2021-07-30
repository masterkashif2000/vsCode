Problem Name : Rod Cutting
Topic : DP
Difficulty : Hard
EXPLANATION
A naive solution for this problem is to generate all configurations of different pieces and find the highest priced configuration. This solution is exponential in term of time complexity. Let us see how this problem possesses both important properties of a Dynamic Programming (DP) Problem and can efficiently solved using Dynamic Programming.

Optimal Substructure: We can get the best price by making a cut at different positions and comparing the values obtained after a cut. We can recursively call the same function for a piece obtained after a cut.

Let cutRod(n) be the required (best possible price) value for a rod of length n. cutRod(n) can be written as following.

cutRod(n) = max(price[i] + cutRod(n-i-1)) for all i in {0, 1 .. n-1}

Time Complexity : O(NN).
#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    int maxValue[n+1];
    memset(maxValue,INT_MIN,sizeof maxValue);
    maxValue[0]=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            maxValue[j]=max(maxValue[j],prices[i]+maxValue[j-i-1]);
        }
    }
    cout<<maxValue[n]<<endl;
    return 0;
}
// 💡 Rod Cutting

