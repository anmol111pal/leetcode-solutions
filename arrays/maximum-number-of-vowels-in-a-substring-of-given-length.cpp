// Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';   
    }

public:
    int maxVowels(string s, int k) {
        int n = s.length();

        int maxVowels = INT_MIN, vowels = 0;
        int i = 0, j = i + k - 1;

        // count the number of vowels in the first window
        for(int x = i; x <= j; x++) {
            if(isVowel(s[x])) {
                ++vowels;
            }
        }

        maxVowels = vowels;

        // slide the window 
        i++;
        j = i + k - 1;

        while(j < n) {
            if(isVowel(s[i-1])) {
                --vowels;
            }

            if(isVowel(s[j])) {
                ++vowels;
            }

            maxVowels = max(maxVowels, vowels);
            
            i++;
            j = i + k - 1;
        }

        return maxVowels;
    }
};