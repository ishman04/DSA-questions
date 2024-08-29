#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
       if (!node) return nullptr;

        unordered_map<Node*, Node*> visited;

        // Put the first node in the queue
        queue<Node*> q;
        q.push(node);

        // Clone the first node and put it in the visited dictionary
        visited[node] = new Node(node->val);

        // Start BFS traversal
        while (!q.empty()) {
            // Pop a node from the front of the queue
            Node* n = q.front();
            q.pop();

            // Iterate through all the neighbors of the node
            for (Node* neighbor : n->neighbors) {
                if (visited.find(neighbor) == visited.end()) {
                    // Clone the neighbor and put it in the visited dictionary
                    visited[neighbor] = new Node(neighbor->val);
                    // Add the neighbor to the queue
                    q.push(neighbor);
                }
                // Add the clone of the neighbor to the neighbors of the clone node
                visited[n]->neighbors.push_back(visited[neighbor]);
            }
        }

        // Return the clone of the first node
        return visited[node];
    }
};