Problem Name : Cell Mitosis
Topic : DP
Difficulty : Hard
EXPLANATION
Time Complexity : O(NN).
Let's define dp[i] as minimum cost to make i number of cells. Then we could write the following recurrence: if i is even dp[i]= min(dp[i/2]+x,dp[i-1]+y} if i is odd dp[i]=min(dp[i-1]+y,dp[i+1/2]+x+z}.

For constraints like N<=10^18, we could do more optimisation. It can be proven that the number of doubling operations should be relatively small (less than 2+log2(n∗max(y,z))). Let's iterate over this number of operations, and call it a.

Without any additions/subtractions, the final number would be 2a. Now, any addition or subtraction can add/subtract any power of two of form 2b, where b≤a, depending on where it is placed. Also, at most one addition/subtraction of 2b with b<a makes sense. In fact, we can argue that n will be formed by satisfying the equation n=2a∗k+b, where |b|<2a. It can be seen that only a handful of values for k make sense in a scenario like this (2 at most).

Let's add cost n div 2a∗y to our current case, and set n′=n mod 2a. Now we're left with an easier problem, writing n′ as a sum of powers of 2, with sign either +1 or −1 (note the fact that the upper bound on the power of 2 has disappeared, this is ultra important). It's important that you convince yourself that we're allowed to do thnt.

This problem can be solved using dp in complexity O(a).

Total complexity is O(log2(n∗(x+y+z))) Source code: https://pastebin.com/84Fcm9SP

#include<bits/stdc++.h>
using namespace std;

int Min(int a,int b,int c){
    return min(a,min(b,c));
}

signed main(){
    int n;
    cin>>n;
    int x,y,z;
    cin>>x>>y>>z;

    int MinCost[n+1];

    MinCost[0]=0;
    MinCost[1]=0;
    MinCost[2]=min(y,x);
    for(int i=3;i<=n;i++){
        MinCost[i]=MinCost[i-1]+y;
        if(i%2==0)MinCost[i]=min(MinCost[i/2]+x,MinCost[i]);
        else{
            MinCost[i]=min(MinCost[i],MinCost[(i+1)/2]+z+x);
        }
    }

    cout<<MinCost[n]<<endl;

    return 0;
}
Java
import java.util.*;
public class Main {
    static class holder implements Comparable<holder>
    {
        int index;
        int value;
        int length;
        public holder(int index,int value,int length)
        {
            this.index=index;
            this.value=value;
            this.length=length;
        }
        public int compareTo(holder o)
        {
            return this.length==o.length? this.index-o.index:o.length-this.length;
        }
        public String toString()
        {
            return this.length+":"+this.value+":"+this.index;
        }
    }
    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);


            int n=scn.nextInt();
            int x=scn.nextInt();
            int y=scn.nextInt();
            int z=scn.nextInt();
            long[] arr=new long[n+1];
            long ans=give(arr, n, x, y, z);
            System.out.println(ans);

    }

    public static long give(long[] arr,int n,int x,int y,int z)
    {
        arr[0]=0;
        arr[1]=0;
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)
            {
                arr[i]=Math.min(arr[i/2]+x, arr[i-1]+y);
            }
            else
            {
                arr[i]=Math.min(arr[i-1]+y,arr[(i+1)/2]+z+x);
            }
        }
        return arr[n];
    }
}
💡 Cell Mitosis