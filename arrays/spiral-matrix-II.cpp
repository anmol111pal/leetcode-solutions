// Link: https://leetcode.com/problems/spiral-matrix-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int x = 1;
        int left = 0, right = n-1, top = 0, down = n-1;

        while(top <= down && left <= right) {
            for(int i = left; i <= right; i++)
                ans[top][i] = x++;
            top++;

            for(int i = top; i <= down; i++)
                ans[i][right] = x++;
            right--;

            if(top <= down) {
                for(int i = right; i >= left; i--)
                ans[down][i] = x++;
                down--;
            }
            
            if(left <= right) {
                for(int i = down; i >= top; i--)
                ans[i][left] = x++;
                left++;
            }
        }

        return ans;   
    }
};