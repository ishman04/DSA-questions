#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen=INT_MIN;
        string str="";
        for(int i=0;i<n;i++){
            // odd case
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxLen<r-l+1){
                    maxLen=r-l+1;
                    str=s.substr(l,r-l+1);
                }
                l--;r++;
            }
            // even case
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(maxLen<r-l+1){
                    maxLen=r-l+1;
                    str=s.substr(l,r-l+1);
                }
                l--;r++;
            }
        }
        return str;
    }
};