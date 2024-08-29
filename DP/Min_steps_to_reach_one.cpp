#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int f(int n){
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=1+min({f(n-1),(n%2==0) ? f(n/2):INT_MAX,(n%3==0)?f(n/3):INT_MAX}); 
}    
int fbu(int n){
    vector<int> dp1(n+1,-1);
    dp1[0]=0;
    dp1[1]=0;
    dp1[2]=1;
    dp1[3]=1;
    for(int i=4;i<=n;i++){
        dp1[i]=1+min({dp1[i-1],(i%2==0)?dp1[i/2]:INT_MAX,(i%3==0)?dp1[i/3]:INT_MAX});
    }
    return dp1[n];
}
int main(){
    int n;
    cin>>n;
    dp.resize(n+5,-1);
    cout<<fbu(n);
}