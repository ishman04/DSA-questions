#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    bool f(vector<int>& nums,int idx){
        if(idx>=nums.size()-1) return 1;
        if(nums[idx]==0) return 0;
        int ans=-1;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=1;i<=nums[idx];i++){
            if(f(nums,idx+i)) return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size()+1,-1);
        return f(nums,0);
    }
};