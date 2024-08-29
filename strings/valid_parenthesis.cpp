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
    bool isValid(string s) {
        stack<char> st;
        if(s.size()==1) return false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(st.empty()) return false;
                if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{') || (s[i]==']' && st.top()=='[')) st.pop();
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }        
};