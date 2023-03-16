// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;

        int max_depth = 0;

        for(const char& ch: s) {
            if(ch == '(') {
                st.push(ch);

                int curr_depth = st.size(); // number of '(' in the stack

                max_depth = max(max_depth, curr_depth);
            }

            else if(ch == ')')
                st.pop();  
        }

        return max_depth;
    }
};