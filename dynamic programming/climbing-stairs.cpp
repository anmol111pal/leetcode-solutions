// Link: https://leetcode.com/problems/climbing-stairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0)  return 0;
        if(n == 1)  return 1;
        if(n == 2) return 2;

        // return climbStairs(n-1) + climbStairs(n-2);

        vector<int> arr(n+1);

        arr[0] = 0;
        arr[1] = 1; // only one way to climb 1 stair
        arr[2] = 2; // two ways to climb 2 stairs (1 step + 1 step OR 2 steps together)

        for(int i = 3; i <= n; i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }

        return arr[n];
    }
};