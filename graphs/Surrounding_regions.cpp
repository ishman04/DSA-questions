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
    int rows;int cols;
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i<0 || j<0 || i>=rows || j>=cols || board[i][j]=='K' || board[i][j]=='X') return;
        board[i][j]='K';
        dfs(board,i+1,j);
        dfs(board,i,j+1);
        dfs(board,i-1,j);
        dfs(board,i,j-1);
    }
    void func(vector<vector<char>>& board,queue<pair<int,int>> q){
        while(!q.empty()){
            auto ele = q.front();
            q.pop();
            int i = ele.first;
            int j = ele.second;
            dfs(board,i,j);
        }
    }
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        rows = board.size();
        cols = board[0].size();
        for(int i=0;i<rows;i++){
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][cols-1]=='O') q.push({i,cols-1});
        }
        for(int i=0;i<cols;i++){
            if(board[0][i]=='O') q.push({0,i});
            if(board[rows-1][i]=='O') q.push({rows-1,i});
        }
        func(board,q);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='K') board[i][j]='O';
            }
        }
    }
};