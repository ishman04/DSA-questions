//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int f(int n,vector<int> &v,int half,int sum,int idx){
         if(sum==half) return 1;
        if(idx==v.size()) return 0;
        if(sum>half) return 0;
        if(dp[sum][idx]!=-1) return dp[sum][idx];
        return dp[sum][idx]=max(f(n,v,half,sum+v[idx],idx+1),f(n,v,half,sum,idx+1));
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        vector<int> vec(arr, arr + N);
        int sum=0;
        for(int i=0;i<vec.size();i++) sum+=vec[i];
        if (sum % 2 != 0) return 0;
        dp.resize(sum,vector<int>(N+1,-1));
        return f(N,vec,sum/2,0,0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends