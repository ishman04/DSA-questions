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
    bool isPalindrome(string s) {
        string original="";
        for(int i=0;i<s.length();i++){
            int c=(int)s[i];
            if(c>=65 && c<=90){
                c+=32;
                original+=(char)c;
            }
            else if((c>=32 && c<=47) || (c>=58 && c<=64) || (c>=123 && c<=255) || (c>=91 && c<=96)) continue;
            else original+=s[i];
        }
        string old=original;
        reverse(original.begin(),original.end());
        if(old==original) return true;
        return false;
    }
};