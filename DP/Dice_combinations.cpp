#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
vector<int> dp(1000005,-1);
int f(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=1;i<=6;i++){
        ans = (ans + f(n-i))%MOD;
    }
    return dp[n]= ans;
}
int main(){
int n;
cin>>n;
cout<<f(n);
}