#include<iostream>
#include<vector>
#include<climits>
#include<sstream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
vector<int> dp;
int n,k;
vector<int> h;
int f(int i){
    if(i>=h.size()) return INT_MAX;
    if(i==h.size()-1) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i+j >= h.size()) break;
        ans=min(ans,abs(h[j+i]-h[i])+f(i+j));
    }
    return dp[i]=ans;
}
int fbu(int i){
    dp.resize(100005,INT_MAX);
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        for(int j=1;j<=k;j++){
            if(i+j >= h.size()) break;
            dp[i]=min(dp[i],abs(h[i]-h[i+j])+dp[i+j]);
        }
    }
    return dp[0];
}
int main(){
cin>>n>>k;
h.resize(n);
for(int i=0;i<n;i++) cin>>h[i];
cout<<fbu(0);
dp.resize(100005,-1);
cout<<f(0);
}