// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), low = 0, high = n-1;

        // only one element, that is the required answer
        if(nums.size() == 1)
            return nums[0];

        if(nums[0] != nums[1]) // if the 1st & 2nd elements aren't same
            return nums[0]; // 1st elem is the single element

        if(nums[n-1] != nums[n-2]) // if the last & second last elements aren't same
            return nums[n-1]; // last element is the single element

        while(low <= high) {
            int mid = low + (high - low)/2;

            // Base case: both neighbours are different
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
                return nums[mid];

            // mid index is even
            if(mid % 2 == 0) {
                if(nums[mid] == nums[mid-1]) // duplicates found at ODD & EVEN index
                    high = mid-1;
                if(nums[mid] == nums[mid+1]) // duplicates found at EVEN & ODD index
                    low = mid+1;
            }
            
            // mid index  is odd
            else if(mid % 2 != 0) {
                if(nums[mid] == nums[mid+1]) // duplicates found at ODD & EVEN index
                    high = mid-1;
                if(nums[mid] == nums[mid-1]) // duplicates found at EVEN & ODD index
                    low = mid+1;
            }
        }
        
        return -1;
    }
};