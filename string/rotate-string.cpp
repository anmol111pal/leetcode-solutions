// Link: https://leetcode.com/problems/rotate-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length())
            return false;

        int i=0, len = s.length();
        
        while(i < len) {
            if(s == goal)
                break;
            // shift the chars
            char first_char = s[0];
            s = s.substr(1) + first_char;
            cout<<s<<endl;
            i++; // to keep a track whether the string has been traversed entirely
        }

        return s == goal;
    }
};