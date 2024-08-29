//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int INF = 1e9;

// Helper function to find the next occurrence of a character in a string
int next_occurrence(const string &T, int start, char c) {
    for (int i = start; i < T.size(); ++i) {
        if (T[i] == c) {
            return i;
        }
    }
    return -1;
}
int shortestUnsubHelper(const string &S, const string &T, int i, int j, vector<vector<int>> &dp) {
    if (i == S.size()) {
        return INF; // Reached the end of S, no valid subsequence found
    }
    if (j == T.size()) {
        return 1; // Reached the end of T, any remaining subsequence in S will not be in T
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // Case 1: Exclude the current character of S
    int exclude = shortestUnsubHelper(S, T, i + 1, j, dp);

    // Case 2: Include the current character of S and find the next occurrence in T
    int nextIndex = next_occurrence(T, j, S[i]);
    int include = (nextIndex == -1) ? 1 : 1 + shortestUnsubHelper(S, T, i + 1, nextIndex + 1, dp);

    // Take the minimum of both cases
    dp[i][j] = min(exclude, include);
    return dp[i][j];
}
    int shortestUnSub(string S, string T) {
        // code here
        vector<vector<int>> dp(S.size(), vector<int>(T.size(), -1));
    int result = shortestUnsubHelper(S, T, 0, 0, dp);
    return (result >= INF) ? -1 : result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends