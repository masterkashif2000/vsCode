// Problem Name : Pairs on line
// Topic : Adhoc, STL
// Difficulty : Easy
// EXPLANATION
// We can store count of all the integers of array, A in a map. Now for each value, Ai, we will add to the answer, the number of occurences of mAi+c

// Time Complexity : O(NlogN)
 
#include <bits/stdc++.h>
#define nn 200100
#define ll long long int
 
using namespace std;
​
ll a[n*n];
​
int main()
{
    map<ll,int>d;
    ll ans=0;
    ll n,m,c;
    cin>>n>>m>>c;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        d[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        ll t=m*a[i] + c;
        if(d.find(t)!=d.end())
        {
            ans+=d[t];
        }
        if(t==a[i])
            ans--;
    }
    cout<<ans<<endl;
    return 0;
}
