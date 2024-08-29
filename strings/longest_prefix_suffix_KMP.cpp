//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++`

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n=s.length();
	    vector<int> arr(n);
	    int prefix=0;
	    int suffix=1;
	    arr[prefix]=0;
	    while(suffix<n){
	        if(s[prefix]==s[suffix]){
	            prefix++;
	            arr[suffix]=prefix;
	            suffix++;
	        }
	        else{
	            if(prefix!=0){
	                prefix=arr[prefix-1];
	            }
	            else{
	                arr[suffix]=0;
	                suffix++;
	            }
	        }
	    }
	    return arr[n-1];
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends