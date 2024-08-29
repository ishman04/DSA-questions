//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution
{
    public:
    // Complete this function
    ll count(ll n) {
        // Initialize dp array with -1 to indicate uncomputed states
         vector<ll> dp(n + 1, 0);
        dp[0] = 1;  // Base case: One way to make score 0 (no coins)

        vector<ll> points = {3, 5, 10};

        // Update the dp array for each coin
        for (ll coin : points) {
            for (ll i = coin; i <= n; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends