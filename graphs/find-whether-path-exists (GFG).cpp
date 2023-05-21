// Link: https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(const pair<int, int>& src, const vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int x = src.first, y = src.second, n = grid.size();
        vis[x][y] = true;
        if(grid[x][y] == 2) return true; // destination
        
        if(x-1 >= 0 && !vis[x-1][y] && grid[x-1][y] != 0) {
            if(dfs({x-1, y}, grid, vis))    return true;
        }
        if(y-1 >= 0 && !vis[x][y-1] && grid[x][y-1] != 0) {
            if(dfs({x, y-1}, grid, vis))    return true;
        }
        if(x+1 < n && !vis[x+1][y] && grid[x+1][y] != 0) {
            if(dfs({x+1, y}, grid, vis))    return true;
        }
        if(y+1 < n && !vis[x][y+1] && grid[x][y+1] != 0) {
            if(dfs({x, y+1}, grid, vis))   return true;
        }
        return false;
    }
    
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        pair<int, int> src;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    src = {i, j};
                    break;
                }
            }
        }
        
        return dfs(src, grid, vis);
    }
};