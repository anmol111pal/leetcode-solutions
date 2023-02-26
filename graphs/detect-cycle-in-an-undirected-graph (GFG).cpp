// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool dfs(int parent, int node, vector<int> adj[], vector<bool>& vis) {
        vis[node] = true;
        
        for(const int& neighbour: adj[node]) {
            if(!vis[neighbour]) {
                if(dfs(node, neighbour, adj, vis))
                    return true;
            }
            else if(neighbour != parent) { // this node has already been visited
                return true; // cycle present
            }
        }
        
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(-1, i, adj, vis)) { // cycle present
                    return true;
                }
            }
        }
        
        return false; // no cycle present
    }
};