#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll f(int n,int v,vector<pair<ll,ll>> &items,int i,vector<vector<ll>> &dp){
    if(v==0) return 0;
    if(i==n) return LLONG_MAX;
    if(dp[i][v]!=-1) return dp[i][v];
    ll ans=LLONG_MAX;
    ans = min(ans,f(n,v, items, i + 1, dp));
    if (items[i].second <= v) {
        ll temp = f(n, v - items[i].second, items, i + 1, dp);
        if (temp != LLONG_MAX) ans = min(ans, items[i].first + temp);
    }
    return dp[i][v] = ans;
}
int main(){
int n,W;
cin>>n>>W;
vector<vector<ll>> dp(105,vector<ll>(100005,-1));
vector<pair<ll,ll>>v(n);
for(ll i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
}
int ans=-1;
for(int i=0;i<=n*pow(10,3);i++){
    if(f(n,i,v,0,dp)<=W) ans=i;
}
cout<<ans;
}
