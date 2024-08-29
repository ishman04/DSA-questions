#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    // Reading the activities' scores
    vector<vector<int>> act(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> act[i][j];
        }
    }

    // Initialize the dp table
    vector<vector<int>> dp(N, vector<int>(3, 0));
    
    // Initialize the first day
    dp[0][0] = act[0][0];
    dp[0][1] = act[0][1];
    dp[0][2] = act[0][2];

    // Fill the dp table
    for (int i = 1; i < N; i++) {
        dp[i][0] = act[i][0] + max(dp[i-1][1], dp[i-1][2]); // If choosing activity 0 on day i
        dp[i][1] = act[i][1] + max(dp[i-1][0], dp[i-1][2]); // If choosing activity 1 on day i
        dp[i][2] = act[i][2] + max(dp[i-1][0], dp[i-1][1]); // If choosing activity 2 on day i
    }

    // Get the maximum value on the last day
    int result = max({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    cout << result << endl;

    return 0;
}
