#include <bits/stdc++.h>
using namespace std;

#include<algorithm>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // the vector isn't sorted
        // if it was sorted, use two-pointer approach
        vector<int> v;
        int n=nums.size();
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int sum=nums[i]+nums[j];
                if(sum == target) {
                    v.push_back(i);
                    v.push_back(j);
                    break;
                }
            }
        }
        return v;
    }
};