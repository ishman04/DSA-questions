#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    int f(vector<int>& nums,int idx,int n){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans = 0;
        ans=max(nums[idx]+f(nums,idx+2,n),f(nums,idx+1,n));
        return dp[idx] = ans;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        dp.resize(nums.size()+1,-1);
        int op1 = f(nums,0,nums.size()-1);
        dp.assign(nums.size(),-1);
        int op2 = f(nums,1,nums.size());
        return max(op1,op2);
    }
};