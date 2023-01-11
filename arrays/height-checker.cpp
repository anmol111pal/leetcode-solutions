// Link: https://leetcode.com/problems/height-checker/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights; // copying to another vector
        sort(expected.begin(), expected.end());

        // checking if both vectors have same elements
        if(heights == expected)
            return 0;

        int count=0;
        int i=0, j=0, n=heights.size();

        while(i < n && j < n) {
            if(heights[i] != expected[j])
                count++;
            i++;
            j++;
        }

        return count;
    }
};