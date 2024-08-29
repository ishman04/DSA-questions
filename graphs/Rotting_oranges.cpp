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
    queue<pair<int,int>> visited;
    int count=0;
    int ans=0;
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    void func(vector<vector<int>>& grid){
        int n=visited.size();
        
        while(!visited.empty()){
            auto ele = visited.front();
            visited.pop();
            int r = ele.first;
            int c = ele.second;
            count++;
            
            for(int i=0;i<4;i++){
                int r1=r+dir[i][0];
                int c1=c+dir[i][1];
                if(r1<0 || c1<0 || r1>=grid.size() || c1>=grid[0].size()) continue;
                if(grid[r1][c1]==2 || grid[r1][c1]==0) continue;
                grid[r1][c1]=2;
                visited.push({r1,c1});
            }
            if(count==n){
                ans++;
                n=visited.size();
                count=0;
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ones=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) visited.push({i,j});
                if(grid[i][j]==1) ones++;
            }
        }
        if(visited.size()!=0) func(grid);
        else{
            if(ones == 0) return 0;
            else return -1;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans-1;
    }
};