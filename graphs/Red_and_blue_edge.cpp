#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <list>
#include <climits>
using namespace std;

vector<list<pair<int, int>>> graph; // adjacency list storing (neighbor, edge color)
int v; // number of vertices
vector<bool> visited;
vector<bool> visited1;
vector<int> sr; // shortest path distances
vector<int> ds; int source, dest;
void add_edge(int src, int dest, bool bi_dir, int color) {
    // red = 1, blue = 2
    graph[src].push_back({dest, color});
    if (bi_dir) {
        graph[dest].push_back({src, color});
    }
}

void calcDistFromSrc(int src, int dist) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    sr[src] = dist;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto ele : graph[curr]) {
            int neighbor = ele.first;
            int color = ele.second;

            if (color == 1 && !visited[neighbor] && neighbor != dest) {
                visited[neighbor] = true;
                sr[neighbor] = sr[curr] + 1;
                q.push(neighbor);
            }
        }
    }
}
void calcDistFromDest(int src,int dist) {
    queue<int> q;
    q.push(src);
    visited1[src] = true;
    ds[src] = dist;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto ele : graph[curr]) {
            int neighbor = ele.first;
            int color = ele.second;

            if (color == 2 && !visited1[neighbor] && neighbor != source) {
                visited1[neighbor] = true;
                ds[neighbor] = ds[curr] + 1;
                q.push(neighbor);
            }
        }
    }
}
int main() {
    cin >> v;
    graph.resize(v);
    visited.resize(v, false);
    visited1.resize(v, false);
    sr.resize(v, INT_MAX);
    ds.resize(v, INT_MAX);
    int e; // number of edges
    cin >> e;
    while (e--) {
        int s, d, c;
        cin >> s >> d >> c;
        add_edge(s, d, true, c);
    }

   
    cin >> source >> dest;

    calcDistFromSrc(source, 0);
    calcDistFromDest(dest, 0);
    for (int i = 0; i < sr.size(); i++) {
        cout << sr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < ds.size(); i++) {
        cout << ds[i] << " ";
    }
    cout<<endl;
    int mini=INT_MAX;
    for(int i=0;i<v;i++){
        mini=min((long long)mini,(long long)sr[i]+(long long)ds[i]);
    }
    cout<<mini;
}

