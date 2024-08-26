//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
  public:
  const int mod = 1e9 + 7;
  vector<long long int> dp;
  long long int f(int h){
      if(h==1) return 1;
      if(h==0) return 1;
      if(dp[h]!=0) return dp[h];
      long long int x = f(h-1);
      long long int y = f(h-2);
      return dp[h]=((x*x)%mod+(2*x*y)%mod)%mod;
  }
    long long int countBT(int h) { 
        // code here
        dp.resize(h+2,0);
        return f(h);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

// } Driver Code Ends