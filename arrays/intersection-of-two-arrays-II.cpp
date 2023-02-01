// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // after sorting, we can easily apply 2-pointer approach

        int i = 0, j = 0, M = nums1.size(), N = nums2.size();

        while(i < M && j < N) {
            if(nums1[i] < nums2[j])
                i++;

            else if(nums2[j] < nums1[i])
                j++;

            else { // found an intersection element
                ans.emplace_back(nums1[i]);
                i++;
                j++;
            }
        }

        return ans;
    }
};