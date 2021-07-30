Problem Name : SHUFFLING
Topic : DP
Difficulty : Hard
EXPLANATION
IDEA : Solve the problem in increasing order of bits, handling carry forward carefully. Dynamic Programming state consists of tuple (bit, cntA, cntB, carry), where bit is the bit position, cntA is number of bits of A not yet used, cntB is number of bits of B not yet used, and carry tells whether we have one carry forward from the previous position or not. Final answer is the value of tuple (0, bit(A), bit(B), carry), where bit(X) counts the number of set bits in XX.

Explanation : This solution seems complicated implementation at first sight, but is actually not, if you are comfortable with Bitwise Operations. Now, we all know, that we A+B should have all bits same as C. We need to count the number of ways to shuffle bits. So, we are going to handle problem bit-by-bit. Important thing is, that If we add two bits at a position, there may be a carry forward to next bit. This means, that bit to be chosen at the next significant position is dependent on carry-forward from the previous position. This means, that we have to approach the bits from least significant bit to most significant bit. So, Suppose we need to have a bit at current position to be xx, with carry-forward cf from the previous position. If x is same as cf, We can either have the current bit set in both numbers or none of them. Because if we choose to have set bit in exactly A or B at the current bit, the current bit will get flipped, resulting in A+B!=C.

If x is not same as y, we have to flip the current bit, which can be done only if exactly one of the A or B have current bit set, which will lead to flipping the current bit.

If you have understood this much, give it a try. After doing this much, If you build a simple recursive solution, we would probably get Time Limit Exceeded, since our solution is calculating some values multiple times, resulting in exponential time complexity.

To speed up, you can just notice, that you can build a lookup table ans[bit][cntA][cntB][carry], storing answer for the tuple (bit, cntA, cntB, carry) and instead of calculating it, just look it up from here. This result in reducing time complexity from exponential to polynomial time complexity, sufficiently fast to pass time limit.

Time Complexity : O($$323232$$).
#include <bits/stdc++.h>

using namespace std;

const int MaxN = (int)2e5 + 10;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;

int bits[1 << 16];
int dp[32][32][32][2];
int cc[32];

int getBits(int x) {
    return bits[x >> 16] + bits[x & 65535];
}

int getWays(int bit, int aa, int bb, int carry) {
    if (bit == 0) {
        return aa == 0 && bb == 0 && carry == 0;
    }
    if (dp[bit][aa][bb][carry] != -1) {
        return dp[bit][aa][bb][carry];
    }
    int &res = (dp[bit][aa][bb][carry] = 0);
    for (int ncarry = 0; ncarry < 2; ++ncarry) {
        for (int ai_1 = 0; ai_1 < 2; ++ai_1) {
            if (aa >= ai_1) {
                for (int bi_1 = 0; bi_1 < 2; ++bi_1) {
                    if (bb >= bi_1) {
                        if ((ncarry + ai_1 + bi_1) / 2 == carry && 
                            (ncarry + ai_1 + bi_1) % 2 == cc[bit - 1]) {
                            res += getWays(bit - 1, aa - ai_1, bb - bi_1, ncarry);
                        }
                    }
                }
            }
        }
    }
    return res;
}

void solve() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    assert (1 <= a && a <= 1e9);
    assert (1 <= b && b <= 1e9);
    assert (1 <= c && c <= 1e9);
    assert (a + b == c);
    for (int i = 0; i < 31; ++i) {
        cc[i] = (c >> i) & 1;
    }
    memset(dp, -1, sizeof(dp));
    cout << getWays(31, getBits(a), getBits(b), 0) << "\n";
}

int main() {
//    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    for (int i = 1; i < 1 << 16; ++i) {
        bits[i] = bits[i / 2] + (i & 1);
    }
    int t;
    scanf("%d", &t);
    while (t --> 0) {
        solve();
    }
    return 0;
}

Approach 2
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[40+1][40+1][40+1][2];
ll give(ll x){
    ll cnt=0;
    while(x){
        if(x&1){
            cnt++;
        }
        x/=2;
    }
    return cnt;
}
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,k,l,m,n;
        ll a,b,c;
        cin>>a>>b>>c;
        string s;
        while(c){
            if(c&1){
                s+='1';
            }
            else{
                s+='0';
            }
            c/=2;
        }
        n=s.size();
        a=give(a);
        b=give(b);
        memset(dp,0,sizeof(dp));
        if(s[0]=='1'){
            dp[0][1][0][0]=1;
            dp[0][0][1][0]=1;
        }
        else{
            dp[0][0][0][0]=1;
            dp[0][1][1][1]=1;
        }
        for(i=1;i<n;i++){
            for(ll x=0;x<=a;x++){
                for(ll y=0;y<=b;y++){
                    if(s[i]=='1'){
                        if(x>=1){
                            dp[i][x][y][0]+=dp[i-1][x-1][y][0];
                        }
                        if(y>=1){
                            dp[i][x][y][0]+=dp[i-1][x][y-1][0];
                        }
                        dp[i][x][y][0]+=dp[i-1][x][y][1];
                        if(x>=1&&y>=1){
                            dp[i][x][y][1]+=dp[i-1][x-1][y-1][1];
                        }

                    }
                    else{
                        dp[i][x][y][0]+=dp[i-1][x][y][0];
                        if(x>=1&&y>=1){
                            dp[i][x][y][1]+=dp[i-1][x-1][y-1][0];
                        }
                        if(x>=1){
                            dp[i][x][y][1]+=dp[i-1][x-1][y][1];
                        }
                        if(y>=1){
                            dp[i][x][y][1]+=dp[i-1][x][y-1][1];
                        }
                    }
                }
            }
        }
        cout<<dp[n-1][a][b][0]<<'\n';
    }
}