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
    void setZeroes(vector<vector<int>>& arr) {
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++) {
                if(arr[i][j]==0)
                v.push_back({i,j});
            }
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<arr.size();j++) arr[j][v[i].second]=0;
            for(int j=0;j<arr[0].size();j++) arr[v[i].first][j]=0;
        }
    }
};
int main(){
    Solution s;
    vector<vector<int>> arr={{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(arr);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
        }
}