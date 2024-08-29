#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
class Solution {
public:
    vector<vector<ll>> dp;
    ll f(int n,int k, int target){
        if(n==0 && target==0) return 1;
        if(target<0 || n==0) return 0;
        ll ans=0;
        if(dp[n][target]!=-1) return dp[n][target]; 
        for(int i=1;i<=k;i++){
            ans= ((ans%mod)+f(n-1,k,target-i)%mod)%mod;
        }
        return dp[n][target]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(35,vector<ll>(1005,-1));
        return f(n,k,target);
    }
};