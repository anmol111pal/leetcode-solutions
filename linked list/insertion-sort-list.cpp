// Link: https://leetcode.com/problems/insertion-sort-list/description/

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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *prev = head, *ptr = prev->next;
        // we will insert ptr into its correct position

        while(prev != NULL && prev->next != NULL) {
            bool swapped = false;
            ptr = prev->next;
            // isolate ptr

            // if the two nodes (prev & ptr) are already in correct order
            if(prev->val <= ptr->val) {
                prev = prev->next;
                continue;
            }

            prev->next = ptr->next;
            
            if(ptr->val <= head->val) { // insert at the head
                ptr->next = head;
                head = ptr;
                swapped = true;
            }

            else {
                ListNode *x = head;
                while(x->next != NULL && x->next->val <= ptr->val)
                    x = x->next;

                // insert at the end
                if(x->next == NULL) {
                    x->next = ptr;
                    ptr->next = NULL;
                    swapped = true;
                    prev = prev->next;
                }
                // insert somewhere in between
                else {
                    ptr->next = x->next;
                    x->next = ptr;
                    swapped = true;
                }
            }
            
            // if no swaps occurred
            if(swapped == false)
                prev = prev->next; // move to the next node & sort
        }

        return head;
    }
};