//Link: https://leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev(1);
        prev[0] = 1;
        ans.push_back(prev);

        if(numRows == 1)
            return ans;
            
        for(int n=1; n < numRows; n++) {
            vector<int> v(n+1);
            v[0] = prev[0];
            v[n] = prev[n-1];

            for(int i=1; i<n; i++)
                v[i] = prev[i] + prev[i-1];

            ans.push_back(v);
            prev = v;
        }

        return ans;
    }
};