// Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> ans;
    void dfs(int node, vector<int> adj[], int vis[]) {
        ans.emplace_back(node);
        vis[node] = 1;
        
        for(int it: adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                dfs(it, adj, vis);
            }
        }
        
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        dfs(0, adj, vis);
        return ans;
    }
};