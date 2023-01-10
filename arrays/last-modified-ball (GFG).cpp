// Link: https://practice.geeksforgeeks.org/problems/33af95e5935f1f2a0c3f5083c4b9d0db68e97bd4/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(int N, vector<int> arr) {
        int pos=N-1, i=N-1;
        
        while(arr[i] == 9 && i >= 0) {
            i--;
            pos--;
        }
        
        return pos + 1;
    }
};