#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[n-1];
        string ans="";
        for(int i=0;i<first.size() && i<last.size();i++){
            if(first[i]==last[i]) ans+=first[i];
            else break;
        }
        return ans;
    }
};