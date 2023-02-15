// Link: https://leetcode.com/problems/permutations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;

       getPermutations(nums, ans, 0);
       
       return ans;
    }

    void getPermutations(vector<int>& arr, vector<vector<int>>& ans, int index) {
        if(index == arr.size()) {
            ans.emplace_back(arr);
            return;
        }

        for(int i = index; i < arr.size(); i++) {
            swap(arr[i], arr[index]);
            getPermutations(arr, ans, index+1);
            swap(arr[i], arr[index]);
        }
    }
};