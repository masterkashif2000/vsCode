Problem Name : Count Number of Binary Strings
Topic : Strings, DP
Difficulty : Hard
EXPLANATION
This problem can be solved using Dynamic Programming. Let a[i] be the number of binary strings of length i which do not contain any two consecutive 1’s and which end in 0. Similarly, let b[i] be the number of such strings which end in 1. We can append either 0 or 1 to a string ending in 0, but we can only append 0 to a string ending in 1. This yields the recurrence relation: a[i] = a[i - 1] + b[i - 1] b[i] = a[i - 1] The base cases of above recurrence are a[1] = b[1] = 1. The total number of strings of length i is just a[i] + b[i]. int countStrings(int n) { int a[n], b[n]; a[0] = b[0] = 1; for (int i = 1; i < n; i++) { a[i] = a[i-1] + b[i-1]; b[i] = a[i-1]; } return a[n-1] + b[n-1]; }

Time Complexity : O(NN).
#include <iostream> 
using namespace std; 

#define int long long 
int countStrings(int n) 
{ 
    int a[n], b[n]; 
    a[0] = b[0] = 1; 
    for (int i = 1; i < n; i++) 
    { 
        a[i] = a[i-1] + b[i-1]; 
        b[i] = a[i-1]; 
    } 
    return a[n-1] + b[n-1]; 
} 

void solve(){
    int n;
    cin>>n;
    cout<<countStrings(n)<<endl;
}

signed main() 
{ 
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0; 
}
Approach 2
// C++ program to count all distinct binary strings // without two consecutive 1's

#include <iostream>
#define ll unsigned long long int
using namespace std;

ll countStrings(int n)
{
    ll a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = (ll)(a[i-1] + b[i-1]);
        b[i] = (ll)a[i-1];
    }
    return (ll)(a[n-1] + b[n-1]);
}


// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        cout << countStrings(n) << endl;
    }
    //cout << countStrings(3) << endl;
    return 0;
}
💡 Count Number of Binary Strings