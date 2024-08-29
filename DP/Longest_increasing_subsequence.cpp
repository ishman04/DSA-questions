#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    int f(vector<int>& nums,int n,int i){
        if(dp[i]!=-1) return dp[i];
        int mx=1;
        for(int j=0;j<=i;j++){
            if(nums[j]<nums[i]){
                mx=max(mx,1+f(nums,n,j));
            }
        }
        return dp[i]=mx;
    }   
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        int ans=-1;
        for(int i=0;i<n;i++){
            ans=max(ans,f(nums,n,i));
        }
        return ans;
    }
};