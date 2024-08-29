#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,l,m;
    cin>>k>>l>>m;
    vector<int> coins(m);
    vector<bool> dp(1000005,0);
    dp[1]=1;
    dp[k]=1;
    dp[l]=1;
    for(int i=0;i<m;i++) cin>>coins[i];
    for(int i=2;i<=1000000;i++){
        if(i==k || i==l) continue;
        dp[i] = !(dp[i-1] && ((i-k>0) ? dp[i-k] : 1) && ((i-l>0) ? dp[i-l] : 1));
    }
    for(int i=0;i<m;i++){
        if(dp[coins[i]]==1) cout<<"A";
        else cout<<"B"; 
    }
}