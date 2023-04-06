// Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> ans;

        for(int i = 0; i < spells.size(); i++) {
            // iterate from the end (as the array is sorted in ascending order)
            int low = 0, high = potions.size() - 1;

            // the index of the minimum number whose product with spells[i] satifies prod >= success
            int startIndex = potions.size();

            while(low <= high) {
                int mid = low + (high - low) / 2;

                long long prod = (long long) spells[i] * potions[mid];

                if(prod >= success) {
                    startIndex = mid;
                    high = mid - 1; // to find the minimum index, search towards left of mid
                }
                else {
                    low = mid + 1; // search towards the right of mid
                }
            }
            int count_of_elem = potions.size() - startIndex;
            ans.emplace_back(count_of_elem);
        }

        return ans;
    }
};