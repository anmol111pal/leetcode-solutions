// Link: https://leetcode.com/problems/factorial-trailing-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int zeroesCount = 0;
        
        int i = 5;
        while(i <= n) {
            zeroesCount += n / i;
            i *= 5;
        }

        return zeroesCount;
    }
};