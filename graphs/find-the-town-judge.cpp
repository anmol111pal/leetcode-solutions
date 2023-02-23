// Link: https://leetcode.com/problems/find-the-town-judge/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // creating the in-degree & out-degree vectors

        vector<int> indegree(n+1), outdegree(n+1);
        indegree[0] = outdegree[0] = -1; // people are labelled from 1 - n

        for(auto& pair: trust) {
            int x = pair[0];
            int y = pair[1];
            // x trusts y
            outdegree[x]++;
            indegree[y]++;
        }

        // for a person to be a judge,
        // its indegree must be n-1 -> all other people must trust the judge.
        // & its outdegree must be 0 -> judge trusts nobody.

        int i = 1;

        while(i <= n) {
            if(indegree[i] == n-1) { // all people trust this person
                if(outdegree[i] == 0) { // this person trusts nobody
                    return i;
                }
            }

            i++;
        }

        return -1; // none of them is the town judge

    }
};