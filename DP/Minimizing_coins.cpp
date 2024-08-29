#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> coins;
vector<int> dp(10000005,-1);
int f(int x){
    if(x==0) return 0;
    if(x<0) return INT_MAX;
    if(dp[x]!=-1) return dp[x];
    int ans=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int res=f(x-coins[i]);
        if(res!=INT_MAX) ans=min(ans,1+res);
    }
    return dp[x]=ans;
}
int main(){
int x;
cin>>n>>x;
coins.resize(n);
for(int i=0;i<n;i++)cin>>coins[i];
int res=f(x);
if(res==INT_MAX) cout<< "-1";
else cout<<res;
}