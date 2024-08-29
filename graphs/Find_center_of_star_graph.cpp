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
    int findCenter(vector<vector<int>>& edges) {
        int center=edges[0][0];
        int center1=edges[0][1];
        if(edges[1][0]==center || edges[1][1]==center) return center;
        if(edges[1][0]==center1 || edges[1][1]==center1) return center1;
        return 0;
    }
};