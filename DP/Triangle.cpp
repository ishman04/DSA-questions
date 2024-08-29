#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int f(vector<vector<int>>& triangle,int n,int i,int j){
        if(i==n-1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = min(triangle[i+1][j]+f(triangle,n,i+1,j),triangle[i+1][j+1]+f(triangle,n,i+1,j+1));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.resize(205,vector<int>(205,-1));
        int n = triangle.size();
        return f(triangle,n,0,0)+triangle[0][0];
    }
};