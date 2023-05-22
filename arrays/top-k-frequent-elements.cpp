// Link: https://leetcode.com/problems/top-k-frequent-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        unordered_map<int, int> mp;
        for(const int& elem: nums) {
            mp[elem]++;
        }

        priority_queue<pair<int, int>> pq; // <count, elem>
        for(const auto& it: mp) {
            int key = it.first;
            int val = it.second;
            pq.push({val, key});
        }

        while(!pq.empty() && k--) {
            int count = pq.top().first, elem = pq.top().second;
            pq.pop();
            ans.emplace_back(elem);
        }       

        return ans;
    }
};