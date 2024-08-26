#include<bits/stdc++.h>
using namespace std;
vector<int> dp(1000005,-1);
int f(int n){
    if(n==0) return 0;
    int k=n;
    vector<int> v;
    if(dp[n]!=-1) return dp[n];
    while(k>0){
        int x=k%10;
        if(x!=0) v.push_back(x);
        k=k/10;
    }
    int minSteps=INT_MAX;
    for(int i=0;i<v.size();i++){
       if(v[i]!=0) minSteps=min(minSteps,1+f(n-v[i]));
    }
    return dp[n]=minSteps;
}
int fbu(int n){
    dp[0]=0;
    for(int i=1;i<=9;i++) dp[i]=1;
    for(int i=10;i<=n;i++){
        int k=i;
        dp[i]=INT_MAX;
        vector<int> v;
        while(k>0){
            int x=k%10;
            if(x!=0) v.push_back(x);
            k=k/10;
        }
        for(int j=0;j<v.size();j++){
            dp[i]=min(dp[i],1+dp[i-v[j]]);
        }
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fbu(n);
}