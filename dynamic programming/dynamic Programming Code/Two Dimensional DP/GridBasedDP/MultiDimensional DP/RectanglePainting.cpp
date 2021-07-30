Problem Name : Rectangle Painting
Topic : DP
Difficulty : Hard
EXPLANATION
Let's solve the problem for rectangle W×H (W≥H). Of course, we can cover all rectangle with itself for cost W. To get something smaller than W we have to leave at least one column uncovered — otherwise we pay at least sum of w over all rectangles which is at least W. This gives us an idea to use DP on rectangles to solve the problem: dp[x1][x2][y1][y2] is minimal cost to cover the rectangle [x1;x2)×[y1;y2). It is initialized by max(x2−x1,y2−y1), and we have to try not to cover every column/row. Of course, we have to check if it is all white from the beginning; to do that we will precalculate 2D prefix sums. Total complexity is O(n5).

Time Complexity : O(N^5N5).
#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int f[N][N][N][N],n,m;char s[N][N];
int dfs(int x,int y,int z,int w)
{
    if(f[x][y][z][w]!=-1)return f[x][y][z][w];
  if(x==z&&y==w)return f[x][y][z][w]=(s[x][y]=='#');
    int ret=max(z-x+1,w-y+1);
    for(int i=x;i<z;i++)ret=min(dfs(x,y,i,w)+dfs(i+1,y,z,w),ret);
    for(int i=y;i<w;i++)ret=min(dfs(x,y,z,i)+dfs(x,i+1,z,w),ret);
    return f[x][y][z][w]=ret;
}
int main()
{
    scanf("%d",&n);memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    printf("%d\n",dfs(1,1,n,n));
}
Approach 2
#include<bits/stdc++.h>

using namespace std;

using namespace std;

char p[60][60];
int n, D[52][52][52][52];
int main() {
    int i, j, k;    
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s", p[i] + 1);
    }
    for (int dx = 1; dx <= n; dx++) {
        for (int dy = 1; dy <= n; dy++) {
            for (int bx = 1; bx + dx - 1 <= n; bx++) {
                for (int by = 1; by + dy - 1 <= n; by++) {
                    int ex = bx + dx - 1, ey = by + dy - 1;
                    if (dx == 1 && dy == 1) {
                        D[bx][by][ex][ey] = (p[bx][by] == '#');
                        continue;
                    }
                    D[bx][by][ex][ey] = max(dx, dy);
                    for (i = bx; i < ex; i++) {
                        D[bx][by][ex][ey] = min(D[bx][by][ex][ey], D[bx][by][i][ey] + D[i + 1][by][ex][ey]);
                    }
                    for (i = by; i < ey; i++) {
                        D[bx][by][ex][ey] = min(D[bx][by][ex][ey], D[bx][by][ex][i] + D[bx][i + 1][ex][ey]);
                    }
                }
            }
        }
    }
    cout<<D[1][1][n][n];
}