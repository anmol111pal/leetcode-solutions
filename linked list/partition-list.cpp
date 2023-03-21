// Link: https://leetcode.com/problems/partition-list/description/

#include <bits/stdc++.h>
using namespace std;

/*  Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;

        ListNode *smaller = new ListNode(-1); // will hold values smaller than x
        ListNode *larger = new ListNode(-1); // will hold values greater than or equal to x

        ListNode *ptr1 = smaller, *ptr2 = larger, *ptr = head;

        while(ptr != NULL) {
            if(ptr->val < x) {
                ptr1->next = ptr; // append to smaller
                ptr1 = ptr1->next;
            }

            else {
                ptr2->next = ptr; // append to larger
                ptr2 = ptr2->next;
            }

            ptr = ptr->next;
        }

        // connecting the two linked lists
        ptr1->next = larger->next;
        ptr2->next = NULL;

        return smaller->next;
    }
};