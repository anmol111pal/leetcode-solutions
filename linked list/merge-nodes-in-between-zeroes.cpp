// Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;

        while(head->val == 0)
            head = head->next;
        
        int sum = 0;

        while(head) {
            if(head->val != 0)
                sum += head->val;
            
            else {
                ptr->next = new ListNode(sum);
                sum = 0;
                ptr = ptr->next;
            }

            head = head->next;
        }

        return dummy->next;
    }
};