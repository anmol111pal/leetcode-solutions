// Link: https://leetcode.com/problems/remove-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        
        // only one elem that is val, so remove it (return 0)
        if(n == 1 && nums[0] == val) 
            return 0;

        for(int i=0; i < n-1; i++) {
            for(int j=i+1; j < n; j++) {

                if(nums[i] != val)
                    break;
                
                while(j < n && nums[j] == val)
                    j++;
                if(j >= n)
                    break;
                else {
                    swap(nums[i], nums[j]);
                    break;
                }
                
            }
        }
        int k=0;
        for(int elem: nums) {
            if(elem != val)
                k++;
            else
                break;
        }

        return k; // number of slots (with numbers other than val)
    }
};