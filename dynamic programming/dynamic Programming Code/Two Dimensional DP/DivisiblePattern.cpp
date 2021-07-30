Problem Name : Divisible Patterns
Topic : DP
Difficulty : Hard
EXPLANATION
Store the occurences of pattern in S in some array 'ind'. Now let's define dp[i][rem] represents the number of ways to choose subset such that product is divisble by 2520. (2520 is lcm(1,2,3,4,5,…,9)).

Time Complexity : O(N*2520N∗2520).
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod = 1e9+7;

void computeLPSArray(string pat, int M, int* lps); 
 vector<int> ind;
void KMPSearch(string& pat, string& txt) 
{ 
    int M = pat.length(); 
    int N = txt.size(); 

    int lps[M]; 
    computeLPSArray(pat, M, lps); 

    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 

        if (j == M) { 
            ind.push_back(i-j);
            j = lps[j - 1]; 
        } 

        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 

void computeLPSArray(string pat, int M, int* lps) 
{ 
    int len = 0; 

    lps[0] = 0; 

    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else
        { 
            if (len != 0) { 
                len = lps[len - 1]; 

            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

int dp[10001][2520];

int fi(int pos,int rem){
    if(pos==ind.size())return (rem==0);
    int &res=dp[pos][rem];
    if(res!=-1)return res;
    res=0;
    res=fi(pos+1,(rem*ind[pos])%2520LL);
    res+=fi(pos+1,rem);
    res%=mod;
    return res;
}

signed main(){
    string pat,txt;
    cin>>pat>>txt;

    KMPSearch(pat,txt);
    for(int i=0;i<ind.size();i++){
        ind[i]=ind[i]+1;
    }
    memset(dp,-1,sizeof dp);

    int ans=fi(0,1);
    ans=(ans%mod+mod)%mod;
    cout<<ans<<endl;

    return 0;
}
Approach 2
/*input
a
aaaaaaa
*/
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define F(i,a,b) for(ll i = a; i <= b; i++)
#define RF(i,a,b) for(ll i = a; i >= b; i--)
#define pii pair<ll,ll>
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
ll z[300005];
void compute_z(string s) // compute z value for each character
{
    ll l=0,r=0;
    ll n = s.length();
    F(i,1,n-1)
    {
        if(i > r)
        {
            l = i , r = i;
            while(r < n && s[r-l] == s[r])
                r++;
            z[i] = r-l;
            r--;
        }
        else
        {
            ll k = i-l;
            if(z[k] < r-i+1)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while(r < n && s[r-l] == s[r])
                    r++;
                z[i] = r-l;
                r--;
            }
        }
    }
}
string pattern,text;
vector <ll> pos;
void compute_occurences()
{
    string s = pattern + "$" + text;
    compute_z(s);
    ll n = s.length();
    F(i,0,n-1)
    {
        if(z[i] == pattern.length())
        {
            //debug(i);
            pos.pb(i - pattern.length());
        }
    }
}
ll dp[10005][4][4][3][3];
ll f(ll i,ll two,ll three,ll five,ll seven)
{
    //cout<<i<<" "<<two<<endl;
    if(i==pos.size())
    {
        if(two>=3 && three>=2 && five>=1 && seven>=1)
        {
            //debug(i);
            return 1;
        }
        return 0;
    }
    if(dp[i][two][three][five][seven] != -1)
        return dp[i][two][three][five][seven];
    ll num = pos[i];
    //debug(num);
    ll t1=0,t2=0,t3=0,t4=0;
    while(num%2==0 && num && t1<=3)
    {
        t1++;
        num /= 2;
    }
    while(num%3==0 && num && t2<=2) 
    {
        t2++;
        num /= 3;
    }
    while(num%5==0 && num && t3<=1)
    {
        t3++;
        num /= 5;
    }
    while(num%7==0 && num && t4<=1)
    {
        t4++;
        num /= 7;
    }
    // if we take current number
    ll a = f(i+1,min(3ll,two+t1),min(2ll,three+t2),min(1ll,five+t3),min(1ll,seven+t4));
    ll b = f(i+1,two,three,five,seven);
    return dp[i][two][three][five][seven] = (a+b)%mod;
}
int main() 
{
    std::ios::sync_with_stdio(false);
    memset(dp,-1,sizeof(dp));
    cin>>pattern>>text;
    compute_occurences();
    cout<<f(0,0,0,0,0)<<endl;
    return 0;
}