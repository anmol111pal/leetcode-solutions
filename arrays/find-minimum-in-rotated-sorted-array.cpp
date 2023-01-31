// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int N = nums.size(), low = 0, high = N-1;

        while(low <= high) {
            int mid = low + (high - low)/2;
            int left = (mid - 1 + N)%N;
            int right = (mid + 1)%N;

            // if the entire array is sorted, return the minimum -> nums[low]
            if(nums[low] <= nums[high])
                return nums[low];

            // minimum element found
            if(nums[mid] <= nums[left] && nums[mid] <= nums[right])
                return nums[mid];

            // left part is sorted, move towards to the right part
            if(nums[low] <= nums[mid])
                low = mid+1;
            // right part is sorted, move towards the left part
            else 
                high = mid-1;
        }
        return -1;
    }
};