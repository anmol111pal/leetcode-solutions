#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        string ans="";
        
        for(char ch: s) {
            if(ch >= 65 && ch <= 90)
                ch += 32; // converting to lowercase
            ans += ch;
        }

        return ans;
    }
};