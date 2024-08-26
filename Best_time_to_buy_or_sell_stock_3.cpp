#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int k,vector<int> &prices,bool on,int i){
        if(i==prices.size() || k==0) return 0;
        if(dp[i][k][on]!=-1) return dp[i][k][on];
        int res=0;
        if(on){
           res=max(f(k,prices,true,i+1),prices[i]+f(k-1,prices,false,i+1));
        }
        else res=max(f(k,prices,false,i+1),f(k,prices,true,i+1)-prices[i]);
        return dp[i][k][on]=res;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size()+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return f(2,prices,false,0);
    }
};