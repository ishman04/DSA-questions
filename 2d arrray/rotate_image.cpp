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
    void rotate(vector<vector<int>>& arr) {
        vector<vector<int>> other=arr;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                arr[i][j]=other[j][i];
            }
            reverse(arr[i].begin(),arr[i].end());
        }
    }
};