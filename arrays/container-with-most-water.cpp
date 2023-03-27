// Link: https://leetcode.com/problems/container-with-most-water/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int max_area = INT_MIN;
        
        while(start < end) {
            int x = end - start;
            int y = min(height[start], height[end]);

            int area = x * y;

            max_area = max(max_area, area);

            if(height[start] <= height[end])
                start++;
                
            else
                end--;
        }

        return max_area;
    }
};