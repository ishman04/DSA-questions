//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here   
        vector<int> v(arr,arr+n);
        int ans=0;
        sort(v.begin(),v.end());
        int i = n-1;
        while(i>=0){
            if(i==0) break;
            int j=i-1;
            if(v[i]-v[j]<k) {
                ans+=v[i]+v[j];
                i=j-1;
            }
            else i=j;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends