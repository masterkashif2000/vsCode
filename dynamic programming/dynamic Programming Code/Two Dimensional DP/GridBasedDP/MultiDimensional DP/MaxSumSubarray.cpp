Problem Name : Maximum Sum Subarray
Topic : DP
Difficulty : Hard
EXPLANATION
The naive solution for this problem is to check every possible rectangle in given 2D array. This solution requires 4 nested loops and time complexity of this solution would be O(n^4).

Kadane’s algorithm for 1D array can be used to reduce the time complexity to O(n^3). The idea is to fix the left and right columns one by one and find the maximum sum contiguous rows for every left and right column pair. We basically find top and bottom row numbers (which have maximum sum) for every fixed left and right column pair. To find the top and bottom row numbers, calculate sun of elements in every row from left to right and store these sums in an array say temp[]. So temp[i] indicates sum of elements from left to right in row i. If we apply Kadane’s 1D algorithm on temp[], and get the maximum sum subarray of temp, this maximum sum would be the maximum possible sum with left and right as boundary columns. To get the overall maximum sum, we compare this sum with the maximum sum so far.

Time Complexity : O($$NNN$$).
#include<bits/stdc++.h>
using namespace std;

#define ROW 1001
#define COL 1001  
 int M[1001][1001];
 // Implementation of Kadane's algorithm for  
// 1D array. The function returns the maximum  
// sum and stores starting and ending indexes  
// of the maximum sum subarray at addresses  
// pointed by start and finish pointers  
// respectively.  
int n,m;
int kadane(int* arr, int* start, 
           int* finish, int n)  
{  
    // initialize sum, maxSum and  
    int sum = 0, maxSum = INT_MIN, i;  

    // Just some initial value to check 
    // for all negative values case  
    *finish = -1;  

    // local variable  
    int local_start = 0;  

    for (i = 0; i < n; ++i)  
    {  
        sum += arr[i];  
        if (sum < 0)  
        {  
            sum = 0;  
            local_start = i + 1;  
        }  
        else if (sum > maxSum)  
        {  
            maxSum = sum;  
            *start = local_start;  
            *finish = i;  
        }  
    }  

    // There is at-least one  
    // non-negative number  
    if (*finish != -1)  
        return maxSum;  

    // Special Case: When all numbers 
    // in arr[] are negative  
    maxSum = arr[0];  
    *start = *finish = 0;  

    // Find the maximum element in array  
    for (i = 1; i < n; i++)  
    {  
        if (arr[i] > maxSum)  
        {  
            maxSum = arr[i];  
            *start = *finish = i;  
        }  
    }  
    return maxSum;  
}  

// The main function that finds 
// maximum sum rectangle in M[][]  
void findMaxSum(int M[][COL])  
{  
    // Variables to store the final output  
    int maxSum = INT_MIN, finalLeft, finalRight,  
                          finalTop, finalBottom;  

    int left, right, i;  
    int temp[n], sum, start, finish;  

    // Set the left column  
    for (left = 0; left < COL; ++left)  
    {  
        // Initialize all elements of temp as 0  
        memset(temp, 0, sizeof(temp));  

        // Set the right column for the left 
        // column set by outer loop  
        for (right = left; right < m; ++right)  
        {  

            // Calculate sum between current left  
            // and right for every row 'i'  
            for (i = 0; i < n; ++i)  
                temp[i] += M[i][right];  

            // Find the maximum sum subarray in temp[].  
            // The kadane() function also sets values   
            // of start and finish. So 'sum' is sum of  
            // rectangle between (start, left) and  
            // (finish, right) which is the maximum sum  
            // with boundary columns strictly as left  
            // and right.  
            sum = kadane(temp, &start, &finish, n);  

            // Compare sum with maximum sum so far.  
            // If sum is more, then update maxSum and  
            // other output values  
            if (sum > maxSum)  
            {  
                maxSum = sum;  
                finalLeft = left;  
                finalRight = right;  
                finalTop = start;  
                finalBottom = finish;  
            }  
        }  
    }  

    cout<<maxSum<<endl;
}  

int main(){
        int t;t=1;
        while(t--){

            cin>>n>>m;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cin>>M[i][j];
                }
            }
            findMaxSum(M);
        }
}
Another Approach
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 #define fio ios_base::sync_with_stdio(false)

#define ll int

#define s(x) scanf("%d",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)

#define p(x) printf("%d\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)

#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

ll maxsum(INT_MIN),maxlef(-1),maxryt(-1),maxup(-1),maxdn(-1),cursum(0);

void init(){
  maxsum=INT_MIN;
  maxlef=-1;
  maxryt=-1;
  maxup=-1;
  maxdn=-1;
  cursum=0;
}

// Function to compute the maximum sum subarray in the passed vector using Kadane's algorithm
// lf and rt are just passed to compute the maxlef and maxryt.
void solve(vector<ll> &kadane, ll lf, ll rt){
  ll n = kadane.size();
  if(n==0)return;
  ll mxsum=kadane[0];
  ll cursum=kadane[0];
  ll stlf=0;
  ll mxlf=0;
  ll mxrt=0;

  for(ll i=1;i<n;i++){
    if(cursum<0){
      cursum=kadane[i];
      stlf=i;
    }else{
      cursum+=kadane[i];
    }

    if(cursum>mxsum){
      mxsum=cursum;
      mxlf=stlf;
      mxrt=i;
    }
  }
  if(mxsum>maxsum){
    maxsum=mxsum;
    maxlef=lf;
    maxryt=rt;
    maxup=mxlf;
    maxdn=mxrt;
  }
}

// O((c*r)^2)
int main()
{
  // freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    init();
    ll r,c;
    s2(r,c);
    vector<vector<ll>> mat;
    mat.resize(r);
    for(ll i=0;i<r;i++){
      mat[i].resize(c);
      for(ll j=0;j<c;j++){
        cin>>mat[i][j];
      }
    }

    vector<ll> kadane;   
    for(ll lf=0;lf<c;lf++){
      kadane.clear();
      kadane.resize(r,0);
      for(ll rt=lf;rt<c;rt++){
        for(ll i=0;i<r;i++){
          kadane[i]+=mat[i][rt];
        }
        solve(kadane,lf,rt);
      }
    }
    cout<<maxsum<<endl;
  }
}


Java Code

import java.util.Scanner;

public class Maximumsumsubarray {

public static void main(String[] args) {
    // TODO Auto-generated method stub
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = s.nextInt();
    }
    int ans = Maximum_Sum_subarray(arr);
    System.out.println(ans);
}

private static int Maximum_Sum_subarray(int[] arr) {
    // TODO Auto-generated method stub
    int max_sum = Integer.MIN_VALUE;
    int curr_sum = 0;
    for (int i = 0; i < arr.length; i++) {
        curr_sum += arr[i];
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
        }
        if (curr_sum < 0) {
            curr_sum = 0;
        }
    }
    return max_sum;
}
}

💡 Maximum Sum Subarray