#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
typedef long long int ll;

int Steps(ll n){
    if(n%3==0){
        n=n/3;
    }
    if(n%2==0){
        n=n/2;
    }
    else{
        n=n-1;
    }
    return ans;
}

int main(){
    ll n;
    cin>>n;
    int ans =min(Steps(n/3),min(Steps(n/2),Steps(n-1)))+1;
    cout<<"the minimum steps are"<<Steps(n)<<endl;an
    return 0;
}
