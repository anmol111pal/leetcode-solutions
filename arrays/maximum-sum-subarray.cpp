// Link: https://leetcode.com/problems/maximum-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using Kadane's algorithm

        int max_sum = INT_MIN;
        int curr_sum = 0;

        for(int elem: nums) {
            curr_sum += elem;

            if(curr_sum > max_sum)
                max_sum = curr_sum;
            
            if(curr_sum < 0)
                curr_sum = 0;
        }

        return max_sum;
    }
};