#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // letters vector is already sorted
        // apply modified binary search

        char ans; // smallest letter greater than target
        bool found=false;
        int low=0, high=letters.size()-1;

        while(low <= high) {
            int mid=low+(high-low)/2;

            if(letters[mid] <= target)
                low=mid+1;

            else if(letters[mid] > target) {
                ans=letters[mid]; // possible ans found
                found=true; 
                high=mid-1; // check further for smallest letter greater than target
            }
        }
        
        if(!found)
            ans=letters[0];
        return ans;
    }
};