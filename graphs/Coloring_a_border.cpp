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
    vector<pair<int,int>> internal;
    vector<pair<int,int>> external;
    void dfs(vector<vector<int>>& grid,int r, int c, int color,int oldcolor){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]!=oldcolor) return;
        grid[r][c]=-color;
        dfs(grid,r+1,c,color,oldcolor);
        dfs(grid,r-1,c,color,oldcolor);
        dfs(grid,r,c+1,color,oldcolor);
        dfs(grid,r,c-1,color,oldcolor);

        //below code is while coming back from recursion
        if( !(r==0 || c==0 || r==grid.size()-1 || c==grid[0].size()-1 || grid[r-1][c]!=-color || grid[r+1][c]!=-color || grid[r][c-1]!=-color || grid[r][c+1]!=-color) ){
            internal.push_back({r,c} );
        }
        else external.push_back({r,c});
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int oldcolor=grid[row][col];
        if(oldcolor==color) return grid;
        dfs(grid,row,col,color,grid[row][col]);
        for(auto ele : internal){
            int r=ele.first;
            int c=ele.second;
            grid[r][c]=oldcolor;
        }
         for(auto ele : external){
            int r=ele.first;
            int c=ele.second;
            grid[r][c]=color;
        }
        return grid;
    }
};