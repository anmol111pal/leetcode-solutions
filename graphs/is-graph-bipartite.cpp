// Link: https://leetcode.com/problems/is-graph-bipartite/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool bfs(int src, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(src);

        int c = 2; // 1 or 2
        color[src] = c;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(color[node] == 1)
                c = 2;
            else
                c = 1;

            for(const int& x: graph[node]) {
                if(color[x] == -1) {
                    q.push(x);
                    color[x] = c;
                }

                // same color found in adjacent nodes
                else if(color[x] == color[node]) {
                    return false; // not bipartite
                }
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        // traverse for all the components in the graph
        for(int i = 0; i < n; i++) {
            // if the current vertice hasn't been colored
            if(color[i] == -1) {
                if(bfs(i, graph, color) == false) {
                    return false; // not bipartite
                }
            }
        }
        
        return true;
    }
};