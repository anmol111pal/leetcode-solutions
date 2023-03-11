// Link: https://leetcode.com/problems/sort-array-by-parity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, n = nums.size();

        // if the initial integers are even
        while(nums[i] % 2 == 0 && i < n-1)
            i++;

        int j = i + 1;

        while(j < n) {
            if(nums[j] % 2 != 0) // odd
                j++;
            
            else { // even  
                swap(nums[i], nums[j]);
                i++;
            }
        }

        return nums;
    }
};