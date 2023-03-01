// Link: https://leetcode.com/problems/sort-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void merge(vector<int>& arr, int low, int mid, int high) {
        int n1 = mid - low + 1, n2 = high - mid;
        vector<int> a(n1), b(n2);

        // filling vector-a
        for(int i = 0; i < n1; i++) {
            a[i] = arr[low+i];
        }

        // filling vector-b
        for(int i = 0; i < n2; i++) {
            b[i] = arr[mid+1+i];
        }

        // merging vector a & b into arr
        int i = 0, j = 0, k = low;

        while(i < n1 && j < n2) {
            if(a[i] < b[j])
                arr[k++] = a[i++];
            else
                arr[k++] = b[j++];
        }

        while(i < n1)
            arr[k++] = a[i++];

        while(j < n2)
            arr[k++] = b[j++];

    }

    void merge_sort(vector<int>& arr, int low, int high) {
        if(low < high) {
            int mid = low + (high - low) / 2;

            merge_sort(arr, low, mid);
            merge_sort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        // applying merge-sort
        
        merge_sort(nums, 0, nums.size()-1);

        return nums;
    }
};