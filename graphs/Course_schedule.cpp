#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& v) {
        vector<list<int>> arr(numCourses);
        for (int i = 0; i < v.size(); i++) {
            arr[v[i][1]].push_back(v[i][0]);
        }
        
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto ele : arr[i]) {
                indegree[ele]++;
            }
        }
        
        queue<int> qu;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) qu.push(i);
        }
        
        int count = 0;
        while (!qu.empty()) {
            int ele = qu.front();
            qu.pop();
            count++;
            for (int n : arr[ele]) {
                indegree[n]--;
                if (indegree[n] == 0) {
                    qu.push(n);
                }
            }
        }
        
        return count == numCourses;
    }
};
