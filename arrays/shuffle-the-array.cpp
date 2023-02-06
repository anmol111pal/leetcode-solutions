// Link: https://leetcode.com/problems/shuffle-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;

        // i is the counter for first half & j is the counter for second half
        int i = 0, j = n;

        while(i < n && j < 2*n) {
            ans.emplace_back(nums[i++]); // copying from first half
            ans.emplace_back(nums[j++]); // copying from second half
        }

        return ans;
    }
};