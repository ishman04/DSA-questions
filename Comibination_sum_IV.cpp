#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp; // Memoization array
    
    int f(vector<int>& nums, int target) {
        if (target == 0) return 1;  // Base case: 1 way to achieve target 0 (by choosing nothing)
        if (target < 0) return 0;    // No way to achieve a negative target
        
        if (dp[target] != -1) return dp[target]; // Return memoized result
        
        int ans = 0;
        for (int num : nums) {
            ans += f(nums, target - num); // Recursively reduce the target
        }
        
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, -1);
        return f(nums, target); 
    }

};