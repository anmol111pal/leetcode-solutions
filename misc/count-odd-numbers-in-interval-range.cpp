// Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int odds = 0;
        
        for(int num = low; num <= high; num++) {
            if(num%2 != 0) {
                odds++;
            }
        }
        
        return odds;
    }
};