// Link: https://leetcode.com/problems/distribute-candies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        map<int, int> mp;
        int n = candyType.size();

        for(int i=0; i<n; i++)
            mp[candyType[i]]++;

        int candyCount = 0;

        auto itr = mp.begin();
        int i = 0;

        while(itr != mp.end() && i < n/2) {
            candyCount++;
            itr++;
            i++;
        }

        return candyCount;
    }
};