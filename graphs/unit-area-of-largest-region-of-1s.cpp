// Link: https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int bfs(int row, int col, const vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        queue<pair<int, int>> q;
        q.push({row, col});
        
        int area = 0;
        
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            vis[i][j] = true;
            area++;
            
            const vector<int> dx = {1, 0, 0, -1, 1, -1, 1, -1};
            const vector<int> dy = {0, 1, -1, 0, -1, 1, 1, -1};
            
            for(int a = 0; a < 8; a++) {
                int x = i + dx[a];
                int y = j + dy[a];
                
                if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0 || vis[x][y])
                    continue;
                q.push({x, y});
                vis[x][y] = true;
            }
        }
        
        return area;
    }
    
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        int max_area = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && !vis[i][j]) {
                    int area = bfs(i, j, grid, vis);
                    max_area = max(max_area, area);
                }   
            }
        }
        
        return max_area;
    }
};