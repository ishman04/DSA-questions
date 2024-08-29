//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define ll long long int
class Solution{
    public:
    const int mod = 1e9+7;
    ll permutationCoeff(int n, int k){
        //Code here
        ll P = 1;

        // Compute P(n, k) = n * (n-1) * ... * (n-k+1)
        for (int i = 0; i < k; i++) {
            P = (P * (n - i)) % mod;
        }

        return P;
    }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        Solution ob;
        int ans = ob.permutationCoeff(n,k);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends