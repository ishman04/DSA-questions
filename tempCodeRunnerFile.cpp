#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
int f(int n,int w,vector<pair<int,int>> &items,int i){
    if(i==n || w==0) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    if(items[i].first>w) return 0;
    return dp[i][w] = max(items[i].second+f(n,w-items[i].first,items,i+1),f(n,w,items,i+1));
}
int main(){
int n,W;
cin>>n>>W;
dp.resize(n+1,vector<int>(W+1,-1));
vector<pair<int,int>>v(n);
for(int i=0;i<n;i++){
    cin>>v[i].first>>v[i].second;
}
cout<< f(n,W,v,0);
}