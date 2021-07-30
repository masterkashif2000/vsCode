/*Problem Name : IPL
Topic : DP
Difficulty : Hard
EXPLANATION
Problem can be formulated as, Given a sequence of positive numbers, find the maximum sum that can be formed which has no three consecutive elements present.

Input: arr[]={1,2,3} Output: 5 We can’t take three of them, so answer is 2+3=5

Input: arr[]={3000,2000,1000,3,10} Output: 5013

Input: arr[]={100,1000,100,1000,1} Output: 2101 100+1000+1000+1=2101

sum[i] : Stores result for subarray arr[0..i], i.e.,maximum possible sum in subarray arr[0..i] such that no three elements are consecutive. sum[0] = arr[0] Note : All elements are positive sum[1] = arr[0] + arr[1] We have three cases 1) Exclude arr[2], i.e., sum[2] = sum[1] 2) Exclude arr[1], i.e., sum[2] = sum[0] + arr[2] 3) Exclude arr[0], i.e., sum[2] = arr[1] + arr[2] sum[2] = max(sum[1], arr[0] + arr[2], arr[1] + arr[2])

In general, We have three cases 1) Exclude arr[i], i.e., sum[i] = sum[i-1] 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i] 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1] sum[i] = max(sum[i-1], sum[i-2] + arr[i], sum[i-3] + arr[i] + arr[i-1])
*/
// Time Complexity : O(NN).
// C++ program to find the maximum sum such that 
// no three are consecutive 
#include <bits/stdc++.h> 
using namespace std; 

// Returns maximum subsequence sum such that no three 
// elements are consecutive 
int maxSumWO3Consec(int arr[], int n) 
{ 
    // Stores result for subarray arr[0..i], i.e., 
    // maximum possible sum in subarray arr[0..i] 
    // such that no three elements are consecutive. 
    int sum[n]; 

    // Base cases (process first three elements) 
    if (n >= 1) 
        sum[0] = arr[0]; 

    if (n >= 2) 
        sum[1] = arr[0] + arr[1]; 

    if (n > 2) 
        sum[2] = max(sum[1], max(arr[1] + arr[2], arr[0] + arr[2])); 

    // Process rest of the elements 
    // We have three cases 
    // 1) Exclude arr[i], i.e., sum[i] = sum[i-1] 
    // 2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i] 
    // 3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1] 
    for (int i = 3; i < n; i++) 
        sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]), 
                     arr[i] + arr[i - 1] + sum[i - 3]); 

    return sum[n - 1]; 
} 
int main(){
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   cout<<maxSumWO3Consec(a,n)<<endl;
}
// Approach 2

/*#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 1000005;
int a[N],dp[N];

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        dp[0]=a[0];
        dp[1]=a[1];
        dp[2]=a[2];
        for(i=3;i<=n;i++){
            dp[i]=a[i]+min({dp[i-3],dp[i-1],dp[i-2]});        
        }
        cout<<dp[n];
    }
}*/

