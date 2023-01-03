#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid. For example, strs = ["abc", "bce", "cae"] can be arranged as:

abc
bce
cae
You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

Return the number of columns that you will delete.

EXAMPLES:

Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.

Input: strs = ["zyx","wvu","tsr"]
Output: 3
Explanation: The grid looks as follows:
  zyx
  wvu
  tsr
All 3 columns are not sorted, so you will delete all 3.
*/


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int count=0;
        int len=strs[0].length();
        int n=strs.size();

        for(int i=0; i<len; i++) {
            for(int j=0; j<n-1; j++) {
                
                string s1=strs[j];
                string s2=strs[j+1];

                char c1=s1[i];
                char c2=s2[i];

                if(c1 > c2) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};