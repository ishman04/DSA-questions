//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> dp;
    int f(int n, vector<int> &a,int idx){
        if(idx>=n) return 0;
        int ans=1;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=0;i<idx;i++){
            if(abs(a[idx]-a[i])==1){
                ans = max(ans,1+f(n,a,i));
            }
        }
        return dp[idx]=ans;
    }
    int longestSubseq(int n, vector<int> &a) {
        dp.resize(n+1,-1);
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,f(n,a,i));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends