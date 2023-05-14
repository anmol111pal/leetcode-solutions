// Link: https://practice.geeksforgeeks.org/problems/269f61832b146dd5e6d89b4ca18cbd2a2654ebbe/1?page=2&difficulty[]=1&category[]=BFS&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helpaterp(vector<vector<int>>& hospital)
    {
        int time = 0;
        int r = hospital.size(), c = hospital[0].size();
        
        vector<vector<bool>> vis(r, vector<bool>(c));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                vis[i][j] = false;
            }
        }
        
        queue<pair<int, int>> q;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(hospital[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        while(!q.empty()) {
            int size = q.size();
            bool flag = false;
            
            for(int i = 1; i <= size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                vis[x][y] = true;
                
                if(x+1 < r && !vis[x+1][y] && hospital[x+1][y] == 1) {
                    q.push({x+1, y});
                    hospital[x+1][y] = 2;
                    flag = true;
                }
                if(y+1 < c && !vis[x][y+1] && hospital[x][y+1] == 1) {
                    q.push({x, y+1});
                    hospital[x][y+1] = 2;
                    flag = true;
                }
                if(x-1 >= 0 && !vis[x-1][y] && hospital[x-1][y] == 1) {
                    q.push({x-1, y});
                    hospital[x-1][y] = 2;
                    flag = true;
                }
                if(y-1 >= 0 && !vis[x][y-1] && hospital[x][y-1] == 1) {
                    q.push({x, y-1});
                    hospital[x][y-1] = 2;
                    flag = true;
                }
            }
            
            if(flag)
                time++;
        }
        
        // check if any uninfected patient is left
        for(const auto& row: hospital) {
            for(const int& elem: row) {
                if(elem == 1) // uninfected patient found
                    return -1;
            }
        }
                
        return time;
    }
};