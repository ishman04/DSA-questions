//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> dp;
    int f(string &str1, string &str2, int idx1,int idx2){
        if(idx1==str1.size() && idx2==str2.size()) return 0;
        if(idx1==str1.size()) return str2.size()-idx2;
        if(idx2==str2.size()) return str1.size()-idx1;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int ans=0;
        if(str1[idx1]==str2[idx2]){
            ans = f(str1,str2,idx1+1,idx2+1);
        }
        else{
            int op1 = f(str1,str2,idx1,idx2+1);
            int op2 = f(str1,str2,idx1+1,idx2);
            int op3 = f(str1,str2,idx1+1,idx2+1);
            
            ans = 1+ min({op1,op2,op3});
        }
        return dp[idx1][idx2]=ans;
    }
    int editDistance(string str1, string str2) {
        // Code here
        dp.resize(str1.size()+1,vector<int>(str2.size()+1,-1));
        return f(str1,str2,0,0);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends