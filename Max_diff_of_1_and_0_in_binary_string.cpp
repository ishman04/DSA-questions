//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	   int n=S.length();
	   vector<int> arr(n);
	   int current_sum = 0;
	   int max_diff=INT_MIN;
	   for(int i=0;i<n;i++){
	       if(S[i]=='1') arr[i]=-1;
	       else arr[i]=1;
	        current_sum = max(arr[i], current_sum + arr[i]);
            max_diff = max(max_diff, current_sum);
	   }
	   return max_diff;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends