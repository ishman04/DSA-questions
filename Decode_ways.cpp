#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    int f(int idx,string &s,int n){
        if(idx==n) return 1;
        int ans=0;
        if(dp[idx]!=-1) return dp[idx];
        if(s[idx]=='0') return 0;
        else{
            ans = f(idx+1,s,n);
            if(idx+1<n){
                string str = s.substr(idx,2);
                int x = stoi(str);
                if(x<=26) ans += f(idx+2,s,n); 
            }
        }
        return dp[idx]=ans;
        
    }
    int numDecodings(string s) {
        int n=s.length();
        dp.resize(n+1,-1);
        return f(0,s,n);
        
    }
};