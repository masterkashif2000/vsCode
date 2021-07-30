// Actual Problem link - For stricter evaluation submit here .

/*input
10 6
1 0 0 6 6
1 9 9 9 10
1 8 5 9 5
2 3 4 5 9 10 9
1 6 6 1 23
2 0 0 0 8 9 10
*/
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define F(i,a,b) for(int i = a; i <= b; i++)
#define RF(i,a,b) for(int i = a; i >= b; i--)
#define pii pair<int,int>
#define PI 3.14159265358979323846264338327950288
#define ll long long
#define ff first
#define ss second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define debug(x) cout << #x << " = " << x << endl
#define INF 1000000009
#define mod 1000000007
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define MX 200
ll BIT[MX+5][MX+5][MX+5];
void update(ll x,ll y,ll z,ll val)
{
    for(ll i=x;i<=MX;i+=i&-i)
    {
        for(ll j=y;j<=MX;j+=j&-j)
        {
            for(ll k=z;k<=MX;k+=k&-k)
            {
                BIT[i][j][k] += val;
            }
        }
    }
}
ll query(ll x,ll y,ll z)
{
    ll sum = 0;
    for(ll i=x;i>0;i-=i&-i)
    {
        for(ll j=y;j>0;j-=j&-j)
        {
            for(ll k=z;k>0;k-=k&-k)
            {
                sum += BIT[i][j][k];
            }
        }
    }
    return sum;
}
int main() 
{
    std::ios::sync_with_stdio(false);
    ll n,q;
    cin>>n>>q;
    ll sum = 0;
    F(i,1,q)
    {
        ll type;
        cin>>type;
        if(type == 1)
        {
            ll x,y,z,val;
            cin>>x>>y>>z>>val;
            x++;y++;z++;
            sum += val;
            update(x,y,z,val);  
        }
        else
        {
            ll x1,y1,z1,x2,y2,z2;
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            x2++;y2++;z2++;
            ll present = query(x2,y2,z2)-query(x1,y2,z2)-query(x2,y1,z2)-query(x2,y2,z1)+query(x1,y1,z2)+query(x1,y2,z1)+query(x2,y1,z1)-query(x1,y1,z1);
            cout<<sum-present<<endl;
        }
    }
    return 0;
}