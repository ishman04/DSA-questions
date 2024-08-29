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
    static bool cmp(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b){
        return a.first<b.first;
    }
   int find(int x,vector<int> &dsu){
     if (dsu[x] != x) {
        dsu[x] = find(dsu[x], dsu); // Path compression
    }
    return dsu[x];
}
void Union(int v1,int v2,vector<int> &dsu,vector<int> &rank){
    int root1=find(v1,dsu);
    int root2=find(v2,dsu);
     if (root1 != root2) {
        if (rank[root1] > rank[root2]) {
            dsu[root2] = root1;
        } else if (rank[root1] < rank[root2]) {
            dsu[root1] = root2;
        } else {
            dsu[root2] = root1;
            rank[root1]++;
        }
    }
    
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                v.push_back({dist,{i,j}});
            }
        }
        sort(v.begin(),v.end(),cmp);
        vector<int> dsu(n);
        int ans=0;
        vector<int> rank(n,0);
        for(int i=0;i<n;i++){
            dsu[i]=i;
        }
        for(int i=0;i<v.size();i++){
            auto u = v[i].second.first;
            auto k = v[i].second.second;
            if(find(u,dsu)!=find(k,dsu)){
                ans+=v[i].first;
                Union(u,k,dsu,rank);
            }
        }
        return ans;
    }
};