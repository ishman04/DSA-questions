//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
         if (S.empty()) return S;

        int j = 0; // j is the index to place the next unique character

        for (int i = 1; i < S.length(); ++i) {
            if (S[i] != S[j]) {
                S[++j] = S[i]; // Increment j and place the next unique character
            }
        }

        S.resize(j + 1); // Resize the string to remove the remaining characters

        return S;
        // code here.
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends