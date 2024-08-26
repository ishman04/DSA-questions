#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int f(int m,int n,int down,int right){
        if(down == m-1 && right == n-1) return 1;
        if(down>=m || right>=n ) return 0;
        if(dp[down][right]!=-1) return dp[down][right];
        return dp[down][right] = f(m,n,down+1,right) + f(m,n,down,right+1);
    }
    int uniquePaths(int m, int n) {
        dp.resize(m+1,vector<int>(n+1,-1));
        return f(m,n,0,0);
    }
};