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
    vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int rows;
    int cols;
    vector<vector<int>> h;
    vector<vector<bool>> func(queue<pair<int,int>>& q){
        vector<vector<bool>> ans(rows,vector<bool> (cols,false));
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int r = ele.first;
            int c = ele.second;
            if(ans[r][c]) continue;
            ans[r][c]=true;
            for(int i=0;i<4;i++){
                int r1 = r + dir[i].first;
                int c1 = c + dir[i].second;
                if(r1<0 || c1<0 || r1>=rows || c1>=cols) continue;
                if(h[r1][c1] < h[r][c]) continue;
                q.push({r1,c1});
            }
        }
        return ans;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> pacificbfs;
        queue<pair<int,int>> atlanticbfs;
        h=heights;
        rows=heights.size();
        cols=heights[0].size();
        //multisource bfs step 
        for(int i=0;i<rows;i++){
            pacificbfs.push({i,0});
            atlanticbfs.push({i,cols-1});
        }
        for(int i=1;i<cols;i++){
            pacificbfs.push({0,i});
        }
        for(int i=0;i<cols-1;i++){
            atlanticbfs.push({rows-1,i});
        }
        vector<vector<bool>> pacific = func(pacificbfs);
        vector<vector<bool>> atlantic = func(atlanticbfs);
        vector<vector<int>> result;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pacific[i][j] && atlantic[i][j]) result.push_back({i,j});
            }
        }
        return result;
    }
};

