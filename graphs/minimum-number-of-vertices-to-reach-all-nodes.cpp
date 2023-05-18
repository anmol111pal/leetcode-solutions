// Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<int> adj[], vector<bool>& vis) {
        vis[node] = true;

        for(const int& x: adj[node]) {
            if(!vis[x]) {
                dfs(x, adj, vis);
            }
        }
    }

public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(const auto& edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].emplace_back(v); // directed edge
        }

        vector<bool> vis(n, false);
        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {
            for(const int& x: adj[i]) {
                ++indegree[x];
            }
        }

        // start the dfs traversal from all the vertices having indegree = 0
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0 && !vis[i]) {
                ans.emplace_back(i);
                dfs(i, adj, vis);
            }
        }
        
        return ans;
    }
};