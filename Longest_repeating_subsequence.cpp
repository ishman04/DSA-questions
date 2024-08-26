//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    vector<vector<int>> dp; 
	    int f(string &str,int i,int j){
	        if(i>=str.size() || j>=str.size()) return 0;
	        if(dp[i][j]!=-1) return dp[i][j];
	        if(str[i]==str[j] && i!=j)return dp[i][j] = 1+f(str,i+1,j+1);
	        else return dp[i][j] = max(f(str,i+1,j),f(str,i,j+1));
	        
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    dp.resize(str.size()+2,vector<int>(str.size()+2,-1));
		    return f(str,0,0);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends