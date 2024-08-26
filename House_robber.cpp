#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    int n;
    int f(vector<int> arr,int i){
        if(i>n-1) return 0;
        if(i==n-1) return arr[i];
        if(dp[i] != -1) return dp[i];
        return dp[i]=max( arr[i] + f(arr,i+2) , f(arr,i+1) );
    }
    int fbu(vector<int> arr,int n){
        if(n<2) return arr[0];
        vector<int> dp1(n);
        dp1[n-1]=arr[n-1];
        dp1[n-2]=max(dp1[n-1],arr[n-2]);
        for(int i=n-3;i>=0;i--){
            dp1[i]=max(arr[i]+dp1[i+2],dp1[i+1]);
        }
        return dp1[0];
    }
    int rob(vector<int>& nums) {
        dp.clear();
        n= nums.size();
        dp.resize(105,-1);
        return fbu(nums,n);

    }
};