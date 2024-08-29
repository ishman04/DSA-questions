#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;
#define ll long long
class Solution {
public:
    vector<ll> unreach;
    unordered_set<int> s;
    void bfs(vector<list<int>> &graph,int src){
        ll count=0;
        queue<int> q;
        q.push(src);
        s.insert(src);
        count=count+1;
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto neighbours : graph[ele]){
                if(s.find(neighbours)==s.end()){
                    count=count+1;
                    q.push(neighbours);
                    s.insert(neighbours);
                }
            }
        }
        if(count!=0) unreach.push_back(count);
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<list<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            if(edges.size()<2) return 0;
            int x=edges[i][0];
            int y=edges[i][1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(int i=0;i<n;i++){
            if(s.find(i)==s.end())
            bfs(graph,i);
        }
        ll ans = 0;
        ll sum = 0; // To keep track of total nodes counted

        for (ll count : unreach) {
            ans += count * sum; // Count pairs between current and previously counted nodes
            sum += count; // Update the total nodes counted
        }
    return ans;
    }
};