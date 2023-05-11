// Link: https://leetcode.com/problems/spiral-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();

        int top = 0, down = m - 1, left = 0, right = n - 1;

        while(left <= right && top <= down) {
            for(int i = left; i <= right; i++)
                ans.emplace_back(matrix[top][i]);
            top++;

            for(int i = top; i <= down; i++)
                ans.emplace_back(matrix[i][right]);
            right--;

            if(top <= down) {
                for(int i = right; i >= left; i--)
                    ans.emplace_back(matrix[down][i]);
                down--;
            }

            if(left <= right) {
                for(int i = down; i >= top; i--)
                    ans.emplace_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};