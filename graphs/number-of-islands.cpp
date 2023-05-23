// Link: https://leetcode.com/problems/number-of-islands/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& vis) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0'|| vis[row][col])
            return;

        vis[row][col] = true;

        // traverse in all 4 directions
        dfs(grid, row+1, col, vis); // dowm
        dfs(grid, row-1, col, vis); // up
        dfs(grid,row, col+1 , vis); // right
        dfs(grid, row, col-1, vis); // left
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int islands = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    islands++;
                    dfs(grid, i, j, vis);
                }
            }
        }

        return islands;
    }
};