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
    static bool cmp(const vector<string> &a,const vector<string> &b){
        return a[1]<b[1];
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> values(n,vector<string>(2));
        
        for(int i=0;i<n;i++) {values[i][0]=strs[i]; values[i][1]=strs[i];}
        vector<vector<string>> ans;
        for(int i=0;i<n;i++) sort((values[i][1]).begin(),(values[i][1]).end());
        sort(values.begin(),values.end(),cmp);
        string curr=values[0][1];
        vector<string> v;
        v.push_back(values[0][0]);
        for(int i=1;i<n;i++){
            if(curr==values[i][1]){
                v.push_back(values[i][0]);
            }
            else{
                ans.push_back(v);
                v.clear();
                curr=values[i][1];
                v.push_back(values[i][0]);
            }
        }
        ans.push_back(v);
        return ans;
    }
};