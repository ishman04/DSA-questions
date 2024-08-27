#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> dp;
    bool f(string& s,int i,int j){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            return dp[i][j]=f(s,i+1,j-1);
        }
        return dp[i][j]= false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int mx=0;
        int start=0;
        dp.resize(s.length()+1,vector<int>(s.length()+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(f(s,i,j) && j-i+1>mx){
                    mx=j-i+1;
                    start = i;
                }
            }
        }
        return s.substr(start,mx);
    }
};