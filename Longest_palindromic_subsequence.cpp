//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<int>> dp;
    int f(string &s,string &r,int i,int j){
        if(i==s.size() || j==r.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==r[j]){
            ans = 1+f(s,r,i+1,j+1);
        }
        else{
            ans = max(f(s,r,i,j+1),f(s,r,i+1,j));
        }
        return dp[i][j]=ans;
    }
    int longestPalinSubseq(string A) {
        //code here
        string r = A;
        reverse(r.begin(),r.end());
        dp.resize(A.length()+1,vector<int>(r.length()+1,-1));
        return f(A,r,0,0);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends