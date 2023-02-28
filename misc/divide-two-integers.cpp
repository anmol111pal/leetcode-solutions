// Link: https://leetcode.com/problems/divide-two-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
            
        if(dividend == 0)
            return 0;

        long quotient = 0;

        long a = abs(divisor);
        long b = abs(dividend);
        
        if(a != 1) {
            // we have to perform b/a
            while(b >= a) {
                b -= a;
                quotient++;
            }
        }

        if(a == 1) {
            quotient = b; // quotient = dividend/1 (a=1)
        }

        // only dividend is -ve OR only divisor is -ve
        if((dividend < 0 && divisor > 0) || (divisor < 0 && dividend > 0))
            quotient = -quotient;

        if(quotient > INT_MAX)
            return INT_MAX;

        if(quotient < INT_MIN)
            return INT_MIN;

        return quotient;
    }
};