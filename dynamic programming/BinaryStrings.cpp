#include<iostream>
using namespace std;

// int countDigits(int n){
//     int a[n+1],b[n+1];
    //Taking index as 0

    // a[0]=b[0]=1;
    // for(int i=1;i<n;i++){
    //     a[i]=a[i-1]+b[i-1];
    //     b[i]=a[i-1];
    // }
    // return a[n-1]+b[n-1];

    //a[i] be the binary strings of length i and ending at 0
    //b[i] be the binary strings of length i and ending at 1

    //Bottom Up Approach
    // a[1]=b[1]=1;
    // for(int i=1;i<=n;i++){
    //     a[i]=a[i-1]+b[i-1];
    //     b[i]=a[i-1];
    // }
    // return a[n]+b[n];

// }

int fibonacciMethod(int n){
    if(n==1){
        return 2;
    }
    else if(n==2){
        return 3;
    }
    else{
        return fibonacciMethod(n-1)+fibonacciMethod(n-2);
    }
        
}

/*int countString(int n,int digit,int dp[]){   
    int a,b;
    if(n==1)return 2;
    if(dp[n]!=0){
        return dp[n];
    }
    if(digit==0){
        a= countString(n-1,0,dp)+countString(n-1,1,dp);
    }
    if(digit!=0){
        b =countString(n-1,0,dp);
    }
    return dp[n]=a+b;
}*/

int main(){
    int n;cin>>n;
    // int dp[n+1]={0};
    // cout<<countDigits(n);
    cout<<fibonacciMethod(n);
    // int x=countString(n,0,dp);
    // int y=countString(n,1,dp);
    // cout<<x+y<<endl;
}
