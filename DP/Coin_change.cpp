#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<int>& coins, int tar,int idx){
        if(idx>=coins.size()) return INT_MAX;
        if(tar==0) return 0;
        if(tar<0) return INT_MAX;
        if(dp[tar][idx]!=-1) return dp[tar][idx];
        int ans = INT_MAX;

        // Include current coin and stay at the same index
        int include = f(coins, tar - coins[idx], idx);
        if (include != INT_MAX) ans = min(ans, 1 + include);

        // Exclude current coin and move to the next index
        int exclude = f(coins, tar, idx + 1);
        ans = min(ans, exclude);

        return dp[tar][idx] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.resize(amount + 1, vector<int>(n, -1));
        int result = f(coins,amount,0);
        return (result==INT_MAX) ? -1 : result;
    }
};