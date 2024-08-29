#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;
class Solution {
public:
    unordered_set<int> visited;
    void func(vector<vector<int>>& rooms,int room){
        queue<int> q;
        q.push(room);
        visited.insert(room);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto r : rooms[curr]){
                if(visited.find(r)==visited.end()){
                    q.push(r);
                    visited.insert(r);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        func(rooms,0);
        if(visited.size()==rooms.size()) return true;
        return false;
    }
};