// Link: https://leetcode.com/problems/find-if-path-exists-in-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool bfs(int src, vector<int> adj[], int dest, vector<bool>& visited) {
        queue<int> q;
        q.push(src);
        
        visited[src] = true;
        if(src == dest)
            return true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;

            for(int neighbour: adj[node]) {
                if(neighbour == dest)
                    return true;

                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }

        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<int> adj[n]; // adjacency list

        // creating an adjacency list
        for(auto x: edges) {
            int u = x[0];
            int v = x[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return bfs(source, adj, destination, visited);
    }
};