//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        int n=A.length();
        int j=n-1;int ans=0;
        unordered_map<char, int> freq;
        for (char c : A) freq[c]++;
        for (char c : B) freq[c]--;
        for (auto f : freq) {
            if (f.second != 0) return -1;
        }
        if(A.length()!=B.length()) return -1;
        for(int i=n-1;i>=0 && j>=0;i--){
            if(A[i]==B[j]){
                j--;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends