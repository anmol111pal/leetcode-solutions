// Link: 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size(), n = score[0].size();
        // applying bubble sort
        for(int i=0; i<=m-2; i++) {
            for(int j=0; j<=m-i-2; j++) {
                
                if(score[j][k] < score[j+1][k]) { // swap entire row
                    for(int x=0; x<n; x++) {
                        swap(score[j][x], score[j+1][x]);
                    }
                }
            }
        }
        return score;
    }
};