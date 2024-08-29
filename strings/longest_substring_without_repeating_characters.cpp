#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        queue<char> q;
        map<char,int> m;
        int currlen=0;
        for(int i=0;i<s.length();i++){
            q.push(s[i]);
            m[s[i]]++;
            if(m[s[i]]>1){
                while(m[s[i]]!=1) {
                    char front=q.front();
                    q.pop();
                    m[front]--;
                }
            }
            currlen=q.size();
            maxlen=max(maxlen,currlen);
        }
        return maxlen;
    }
};