#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int n;
        cin>>n;
    int a[n];
    int max =0;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      if(max<a[i])
        max = a[i];
    }
// For each number of the sequence , calculating number of ways

  int fib_num[max];
  fib_num[0]=1;
  fib_num[1]=2;
    for(int i=2;i<max;i++)
    {
       fib_num[i]=fib_num[i-1]+fib_num[i-2];
    }

 //Sum up all the ways of the selected number 
 //sum1 = Sum of ways for player one
 //sum2 = Sum of ways for player two  
      int sum1 =0 , sum2=0;
      int i=0;
      int m =n;
    for(int k=1;k<=m;k++)
    {
      if(k%2==1)
      {
         if(a[i]>a[n-1])
         {
          sum1+=fib_num[a[i]-1];
          i++;
         }
        else
        {
          sum1+=fib_num[a[n-1]-1];
          n--;
        }
      }
      else
      {
        if(a[i]>a[n-1])
        {
          sum2+=fib_num[a[i]-1];
          i++;
        }
        else
        {
          sum2+=fib_num[a[n-1]-1];
          n--;
        }
      }
    }

    /*cout<<sum1<<" "<<sum2<<"\n";*/
     if(sum1>sum2)
      cout<<"First"<<"\n";
    else if(sum2>sum1)
      cout<<"Second"<<"\n";
    else
      cout<<"Tie"<<"\n";
  }
}
