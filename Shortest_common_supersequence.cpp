#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>> dp;
    int m,n;
    string ans="";
    int f(string &s1,string &s2,int i,int j,string out){
        if(ans.size()<out.size()) ans=out;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if (s1[i] == s2[j]){
            return dp[i][j] = 1 + f(s1, s2, i - 1, j - 1, out+s1[i]);
        } else {
            return dp[i][j] = max(f(s1, s2, i - 1, j, out), f(s1, s2, i, j - 1, out));
        }
    }
    void ShortestCommonSupersequence(string str1, string str2) {
        dp.resize(1005,vector<int>(1005,-1));
        n=str1.size();
        m=str2.size();
        f(str1,str2,n-1,m-1,"");
        int i=0,j=0;
        string sol="";
        reverse(ans.begin(),ans.end());
        cout<< ans<<endl;
        for(char c : ans){
            while(i<n && str1[i]!=c) sol+=str1[i++];
            while(j<m && str2[j]!=c) sol+=str2[j++];
            sol+=c;
            i++;
            j++;
        }
        if(i<n) sol+=str1.substr(i);
        if(j<m) sol+=str2.substr(j);
        cout<< sol;
    }
int main(){
    string str1;
    string str2;
    cin>>str1>>str2;
    ShortestCommonSupersequence(str1,str2);
}