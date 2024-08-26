#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> dp;
int f(string &s1, string &s2, int i,int j,int k){ 
    if(i<0 || j<0) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    int res=0;
    if(s1[i]==s2[j]){
        res=1+f(s1,s2,i-1,j-1,k);
    }
    else{
        if(k>0){
            res=max({1+f(s1,s2,i-1,j-1,k-1),f(s1,s2,i-1,j,k),f(s1,s2,i,j-1,k)});
        }
        else res= max({f(s1,s2,i-1,j,k),f(s1,s2,i,j-1,k)});
    }
    return dp[i][j][k]=res;
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    string s1,s2;
    cin>>s1>>s2;
    dp.resize(2005,vector<vector<int>>(2005,vector<int>(8,-1)));
    cout<<f(s1,s2,s1.length()-1,s2.length()-1,k);
}