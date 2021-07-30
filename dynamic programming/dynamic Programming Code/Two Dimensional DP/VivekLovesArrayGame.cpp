Problem Name : Vivek Loves Array Game
Topic : DP
Difficulty : Hard
EXPLANATION
Let's say we have a recursive function F(a,l,r) which gives the maximum possible score if we chose only a[l..r]. It's easy to define F as F(l,r)=1+max(F(l,ind),F(ind+1,r)) , where ind is the index 'j' such that sum of a[l..ind]=a[ind+1..r]. which we can find it iteratively. Since each element will be visited only once by recursion , so there are O(n) for recursive call and since in each recursive call we are finding the value of 'ind' so it could take upto O(n). So in total O(n*n).

Time Complexity : O(N*NN∗N).
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> pre;
map<pair<int,int>,int> my;
int maxScore(vector<int> &a,int l,int r){
    if(l==r)return 0LL;
    if(l>r)return 0LL;
    int totalSum=pre[r]-(l?pre[l-1]:0);
    int ind;
    if(totalSum%2)return 0LL;
    int sum=0;
    bool flag=false;
    for(int j=l;j<=r;j++){
        sum+=a[j];
        if(sum==(totalSum/2)){
            ind=j;
            flag=true;
            break;
        }
    }
    if(!flag)return 0;

    return 1+max(maxScore(a,l,ind),maxScore(a,ind+1,r));
}

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);cout.tie(0);
    int t;
    scanf("%lld",&t);
    while(t--){
        int n;
        scanf("%lld",&n);
        pre.clear();
        pre.resize(n);
        my.clear();
        vector<int> a(n);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
            if(i==0)pre[i]=a[i];
            else pre[i]=pre[i-1]+a[i];
        }

        printf("%lld\n",maxScore(a,0,n-1));
    }
    return 0;
}
Another Approach
Hacks
To Solve any Problem related to Recursion All you need to do is Break the Problem into 3 important components which are as follows :-

1.Bigger Problem : The original Problem statement is your bigger problem.
2.Smaller Problem: In every recursive prblm there exist a prblm statement which you need to achieve in order to fullfill the prblm statement but by considering such a smaller prblm from the bigger prblm is needed which we need to assume that the recursion will work and will give the answer.
3.Self Work: The amount of work which one should do in order to make the smaller problem your problem.

For e.g.., In order to find the max of any array, three components will be :-
Bigger Problem : To find the max in whole array viz find max in array from index 0 to n - 1.
Smaller Problem: Assume that the recursion works and will find the max of array from index 1 to n - 1.
__Self work : In order to make your smaller prblm your bigger prblm all you need to do is to compare the ans return by assuming the smaller prblm works with the 0th index element and return the max among both of them.

Similarly Classification acc to the Given prblm :-

Bigger Problem : To print the max score by playing accoring to the rule.
Smaller Problem : Assume the recursion works and will give you ans for every Partition you made for e.g..,
For range [0 - N] partition can be [0-1] and [2 - N] or [0 - 2] and [3 - N].
Self Work : In order to make your smaller problem your bigger problem all you need is to check if the two paritions generated has equal sum or not. and further store the max count in another variable.
Note : There are variable smaller prblms so we will use call in a loop depending on the partition created.

Code


    private static int maxScore(int[] arr, int si, int ei) {

        if (si > ei)
            return 0;
        int fh = 0, sh = 0;
        for (int i = si; i < ei; i++) {
            int sum1 = sum(arr, si, i);
            int sum2 = sum(arr, i + 1, ei);
            if (sum1 == sum2) {
                fh = maxScore(arr, si, i);
                sh = maxScore(arr, i + 1, ei);
                return Math.max(fh, sh) + 1;
            }

        }
        return 0;

    }

    private static int sum(int[] arr, int si, int ei) {

        int sum = 0;
        for (int i = si; i <= ei; i++)
            sum += arr[i];
        return sum;
    }