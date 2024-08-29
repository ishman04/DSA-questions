#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>dp;
int f(vector<pair<int,int>> &v,int x,int i){
    int ans=0;
    if(i==n) return 0;
    if(dp[i][x]!=-1) return dp[i][x]; 
    if(x==0) ans = v[i].second + f(v,x+1,i+1);
    else if(x==n-i) ans = v[i].first + f(v,x-1,i+1);
    else ans = min(v[i].first+f(v,x-1,i+1),v[i].second + f(v,x+1,i+1));
    return dp[i][x]=ans; 
}
int main(){
    
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    dp.resize(n+1,vector<int>(n+1,-1));
    cout<<f(v,0,0);
}