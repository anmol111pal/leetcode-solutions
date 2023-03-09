// Link: https://leetcode.com/problems/roman-to-integer/description/

#include <bits/stdc+++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int len = s.size();
        int res = 0;
        
        for(int i=0; i < len-1; i++) {
            char c = s[i];
            
            if(mp[c] >= mp[s[i+1]])
                res += mp[c];
            else 
                res -= mp[c];
        }

        res += mp[s[len-1]];
        
        return res;
    }
};