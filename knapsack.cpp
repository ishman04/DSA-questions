#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll f(int n,int w,vector<pair<ll,ll>> &items,int i,vector<vector<ll>> &dp){
    if(i==n || w==0) return 0;
    if(dp[i][w]!=-1) return (ll)dp[i][w];
    ll ans=0;
    if(items[i].first>w) ans = f(n, w, items, i + 1, dp);
    else ans = (ll) max(items[i].second+f(n,w-items[i].first,items,i+1,dp),f(n,w,items,i+1,dp));
    return dp[i][w] = ans;
}
int main(){
int n,W;
cin>>n>>W;
vector<vector<ll>> dp(n+1,vector<ll>(W+1,-1));
vector<pair<ll,ll>>v(n);
for(ll i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
}
cout<< f(n,W,v,0,dp);
}
