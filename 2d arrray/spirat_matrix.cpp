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
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int y=arr.size();
        int x=arr[0].size();
        int top=0;int bottom=y-1;int left=0;int right=x-1;
        vector<int> ans;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++) ans.push_back(arr[top][i]);
            top++;
            for(int i=top;i<=bottom;i++) ans.push_back(arr[i][right]);
            right--;
             if (top <= bottom) {
                // Traverse from right to left along the bottom row
                for (int i = right; i >= left; --i) ans.push_back(arr[bottom][i]);
                --bottom;
            }
            
            if (left <= right) {
                // Traverse from bottom to top along the left column
                for (int i = bottom; i >= top; --i) ans.push_back(arr[i][left]);
                ++left;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7
    ,8,9}};
    vector<int> ans=s.spiralOrder(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
        }
}