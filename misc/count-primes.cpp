// Link: https://leetcode.com/problems/count-primes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {

        if(n < 2)
            return 0; // there are no primes less than 2
        
        // use Sieve of Eratosthenes
        
        vector<bool> sieve(n, true);
        int count = 0;

        sieve[0] = sieve[1] = false; // 0 & 1 are non-primes

        // remove elements from sieve

        for(long num = 2; num*num < n; num++) {
            if(sieve[num] == true) {
                for(long i = num*num; i < n; i += num) {// marking all multiples of num as non-primes, starting from the square of the num
                    sieve[i] = false;
                }
            }
        }

        // counting the primes less than n
        for(int i = 2; i < sieve.size(); i++) {
            if(sieve[i] == true) {
                count++;
            }
        }
        
        return count;
    }
};