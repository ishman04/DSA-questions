//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        if (s.empty() || p.empty()) {
        return "-1";
    }
    
    vector<int> countP(128, 0);  // Assuming ASCII characters
    for (char c : p) {
        countP[c]++;
    }
    
    int n = s.size();
    int required = p.size();
    int left = 0, min_len = INT_MAX, min_start = 0, formed = 0;
    vector<int> windowCount(128, 0);
    
    for (int right = 0; right < n; ++right) {
        char char_right = s[right];
        windowCount[char_right]++;
        
        if (countP[char_right] > 0 && windowCount[char_right] <= countP[char_right]) {
            formed++;
        }
        
        while (formed == required) {
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_start = left;
            }
            
            char char_left = s[left];
            windowCount[char_left]--;
            
            if (countP[char_left] > 0 && windowCount[char_left] < countP[char_left]) {
                formed--;
            }
            
            left++;
        }
    }
    
    if (min_len == INT_MAX) {
        return "-1";
    } 
        return s.substr(min_start, min_len);

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
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends