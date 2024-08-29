#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
vector<vector<int>> dir = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
vector<vector<int>> result;
int func(pair<int, int> knightPosition, pair<int, int> targetPosition, int size,queue<pair<int,int>> q){
    while(!q.empty()){
        auto ele = q.front();
        q.pop();
        int j=ele.first;
        int i=ele.second;
        
        for(int a=0;a<8;a++){
            int nj = j+dir[a][0];
            int ni = i+dir[a][1];
            if(ni<1 || nj<1 || ni>size || nj>size || result[size-ni][nj-1]!=-1) continue;
            else{
                result[size-ni][nj-1]=result[size-i][j-1]+1;
                q.push({ni,nj});
                if(ni==targetPosition.second && nj==targetPosition.first) return result[size-ni][nj-1];
            }
        }
    }
    return -1;
}
int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size) {
    // Write your code here.
    queue<pair<int,int>> q;
    q.push(knightPosition);
    result.resize(size,vector<int> (size,-1));
    result[size-knightPosition.second][knightPosition.first-1]=0;
    return func(knightPosition,targetPosition,size,q);
}
