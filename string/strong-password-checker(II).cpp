#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int len = password.length();

        if(len < 8)
            return false;

        unsigned int uppercase_count=0, lowercase_count=0, digit_count=0,spl_char_count=0;
        for(int i=0; i<len; i++) {
            char ch = password[i];

            if(ch >= 65 && ch <= 90)
                uppercase_count++;
            else if(ch >= 97 && ch <= 122)
                lowercase_count++;
            else if(ch >= 48 && ch <= 57)
                digit_count++;
            else
                spl_char_count++;
        }

        if(uppercase_count < 1 || lowercase_count < 1 || digit_count < 1 || spl_char_count < 1)
            return false;

        // checking for consecutive characters
        for(int i=0; i<len-1; i++) {
            if(password[i] == password[i+1])
                return false;
        }
        
        return true;
    }
};