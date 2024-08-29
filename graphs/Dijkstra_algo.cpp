#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;
vector<list<pair<int,int>>> gr;
void add_edge(int v,int u,int wt,bool bidir=true){
     gr[u].push_back({v,wt});
     if(bidir) gr[v].push_back({u,wt});
}
unordered_map<int,int> mp;
void dijkstra(int src,int n){
    priority_queue<pp, vector<pp>,greater<pp>> pq;
    unordered_set<int> visited;
    vector<int> par(n);
    pq.push({0,src});
    for(int i=0;i<n;i++){
        mp[i]=INT_MAX;
    }
    mp[src]=0;
    while(!pq.empty()){
        auto ele = pq.top();
        int wt=ele.first;
        int node=ele.second;
        pq.pop();
        if(visited.find(node)!=visited.end()) continue;
        visited.insert(node);
        for(auto it:gr[node]){
            if(!visited.count(it.first) and mp[it.first]>it.second+mp[node]){
                pq.push({it.second+mp[node],it.first});
                par[it.first]=node;
                mp[it.first]=it.second+mp[node];
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n);
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    dijkstra(src,n);
    for(int i=0;i<n;i++) cout<<mp[i]<<" ";

}