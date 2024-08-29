#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> result;
        result.resize(row,vector<int>(col,INT_MAX));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                   q.push({i,j}); 
                    result[i][j]=0;
                } 
            }
        }
        vector<vector<int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
        while(!q.empty()){
            auto ele=q.front();
            int r=ele.first;
            int c=ele.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                if(nr>=row || nc>=col || nr<0 || nc<0) continue;
                if(result[nr][nc]>result[r][c]+1){
                    result[nr][nc]=result[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return result;
    }
};