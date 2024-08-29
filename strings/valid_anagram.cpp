#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;
        if(s.length()!=t.length()) return false;
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(int i=0;i<s.length();i++){
            if(m1[s[i]]==m2[s[i]]) continue;
            else return false;
        }
        return true;
    }
};