//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> dp;
    int f(vector<int> &arr,int i,int flag){
        if(i==0) return 1;
        if(dp[i][flag]!=-1) return dp[i][flag];
        int ans = 1;
        for(int j=0;j<i;j++){
            if(flag==0 && arr[j]<arr[i]){
                ans = max(ans,1+f(arr,j,1));
            }
            else if(flag==1 && arr[j]>arr[i]){
                ans = max(ans,1+f(arr,j,0));
            }
        }
        return dp[i][flag]=ans;
    }
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int n = arr.size();
        dp.resize(n+1,vector<int>(2,-1));
        int result = 0;
        for(int i=0;i<n;i++){
            result = max(result,f(arr,i,0));
            result = max(result,f(arr,i,1));
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends