#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    int f(string &s1,string &s2,int i,int j){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if (s1[i] == s2[j]){
            return dp[i][j] = 1 + f(s1, s2, i - 1, j - 1);
        } else {
            return dp[i][j] = max(f(s1, s2, i - 1, j), f(s1, s2, i, j - 1));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(10005,vector<int>(1005,-1));
        return f(text1,text2,text1.length()-1,text2.length()-1);
    }
};