// Link: https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), freshOranges = 0;

        bool vis[m][n];
        for(auto& row: vis) {
            for(auto& elem: row)
                elem = false;
        }

        int time = 0;

        queue<pair<int, int>> q;
        
        // push all the cells having rotten oranges
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    freshOranges++;
            }
        }

        if(freshOranges == 0)   return 0;

        while(!q.empty()) {
            int size = q.size();
            int flag = 0; // this will indicate whether a neighbouring orange has been rotten or not

            while(size--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                vis[x][y] = true;

                // push all the neighbours
                if(x+1 < m && !vis[x+1][y] && grid[x+1][y] == 1) {
                    q.push({x+1, y});
                    grid[x+1][y] = 2; // rotten
                    flag = 1;
                }
                if(y+1 < n && !vis[x][y+1] && grid[x][y+1] == 1) {
                    q.push({x, y+1});
                    grid[x][y+1] = 2; // rotten
                    flag = 1;
                }
                if(x-1 >= 0 && !vis[x-1][y] && grid[x-1][y] == 1) {
                    q.push({x-1, y});
                    grid[x-1][y] = 2; // rotten
                    flag = 1;
                }
                if(y-1 >= 0 && !vis[x][y-1] && grid[x][y-1] == 1) {
                    q.push({x, y-1});
                    grid[x][y-1] = 2; // rotten
                    flag = 1;
                }
            }
            if(flag)    // if we have rotten an orange in the current BFS traversal
                time++;
        }

        // check if any fresh orange is left, after the traversal
        for(const auto& row: grid) {
            for(const int& elem: row) {
                if(elem == 1) // found a fresh orange
                    return -1;
            }
        }

        return time;
    }
};