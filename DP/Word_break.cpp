#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, bool> memo;

    bool wordBreakHelper(const string &s, const unordered_set<string> &wordDict, int start) {
        if (start == s.length()) {
            return true;
        }
        
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }
        
        for (int end = start + 1; end <= s.length(); ++end) {
            string prefix = s.substr(start, end - start);
            if (wordDict.find(prefix) != wordDict.end() && wordBreakHelper(s, wordDict, end)) {
                return memo[start] = true;
            }
        }
        
        return memo[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return wordBreakHelper(s, wordSet, 0);
    }
};