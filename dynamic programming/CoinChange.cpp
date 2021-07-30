#include<iostream>
using namespace std;
// typedef long long int ll;

// Returns the count of ways we can  
// sum S[0...m-1] coins to get sum n 
int count(int a[],int m,int sum){
    // If sum is 0 then there is 1 solution  
    // (do not include any coin) 
    if(sum==0){
        return 1;
    }
    // If sum is less than 0 then no  
    // solution exists 
    if (sum < 0) 
        return 0;
    // If there are no coins and sum  
    // is greater than 0, then no 
    // solution exist  
    if(m<=0 && sum>=1){
        return 0;
    }
    // count is sum of solutions   
    // (i) including S[m-1] 
    //(ii) excluding S[m-1] 
    return count(a,m,sum-a[m-1])+count(a,m-1,sum);
}

int main(){
    //Recursive approach
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    printf("%d ", count(arr, m, 4)); 
}