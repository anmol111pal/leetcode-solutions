// Link: https://leetcode.com/problems/random-pick-index/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<int>> mp; // to store the number with the corresponding indices
    
public:
    Solution(vector<int>& nums) {
        const int n = nums.size();

        for(int i = 0; i < n; i++) {
            mp[nums[i]].emplace_back(i);
        }

        srand(time(0));
    }
    
    int pick(int target) {
        const int n = mp[target].size(); // number of repeated elements
        const int index = rand() % n; // random index

        const vector<int>& indices = mp[target];
        // indices-vector has the indices of the target element

        return indices[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */