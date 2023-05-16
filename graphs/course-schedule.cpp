// Link: https://leetcode.com/problems/course-schedule/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(const auto& edge: prerequisites) {
            int u = edge[0], v = edge[1];
            adj[u].emplace_back(v);
        }

        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(const int& node: adj[i]) {
                indegree[node]++;
            }
        }
        
        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while(!q.empty()) {
            bool flag = false;
            int node = q.front();
            q.pop();
            topo.emplace_back(node);

            for(int& x: adj[node]) {
                indegree[x]--;
                if(indegree[x] == 0) {
                    q.push(x);
                }
            }
        }

        if(topo.size() == numCourses)
            return true;
        return false;
    }
};
