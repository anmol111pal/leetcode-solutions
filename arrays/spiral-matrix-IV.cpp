// Link: https://leetcode.com/problems/spiral-matrix-iv/description/

#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n));
        
        int left = 0, right = n-1, top = 0, down = m-1;
        int x = head ? head->val : -1;

        while(top <= down && left <= right) {
            for(int i = left; i <= right; i++) {
                ans[top][i] = x;
                if(head) {
                    head = head->next;
                    x = head ? head->val : -1;
                }
            }
            top++;           

            for(int i = top; i <= down; i++) {
                ans[i][right] = x;
                if(head) {
                    head = head->next;
                    x = head ? head->val : -1;
                }
            }
            right--;

            if(top <= down) {
                for(int i = right; i >= left; i--) {
                    ans[down][i] = x;
                    if(head) {
                        head = head->next;
                        x = head ? head->val : -1;
                    }
                }
                down--;
            }

            if(left <= right) {
                for(int i = down; i >= top; i--) {
                    ans[i][left] = x;
                    if(head) {
                        head = head->next;
                        x = head ? head->val : -1;
                    }
                }
                left++;
            }
        }

        return ans;
    }
};