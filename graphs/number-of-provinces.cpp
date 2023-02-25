// Link: https://leetcode.com/problems/number-of-provinces/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;

        for(const int& neighbour: adj[node]) {
            if(!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // isConnected is the adjacency matrix
        int n = isConnected.size(); // number of vertices

        // creating adjacency list
        vector<int> adj[n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;
                
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);

        int provinces = 0;

        // traversing through all the vertices of the graph, 
        // connected as well as disconnected components

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                provinces++;
                dfs(i, adj, visited);
            }
        }

        return provinces;
    }
};