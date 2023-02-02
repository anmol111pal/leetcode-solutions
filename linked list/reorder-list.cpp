// Link: https://leetcode.com/problems/reorder-list/description/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.  */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // function to reverse the linked-list
    ListNode* reverse(ListNode* head) {
        ListNode *curr = head, *prevPtr = NULL, *nextPtr=NULL;

        while(curr != NULL) {
            nextPtr = curr->next;

            curr->next = prevPtr;
            prevPtr = curr;
            curr = nextPtr;
        }
        return prevPtr;
    }

    // function to get the middle node of the linked-list
    ListNode* getMiddleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // middle node
    }

    void reorderList(ListNode* head) {
        // find the middle node of the linked-list
        ListNode *middle = getMiddleNode(head);

        ListNode *p = head; // first linked-list
        // reverse the linked-list after the middle node
        ListNode *q = reverse(middle->next); // second linked-list

        middle->next = NULL; // to separate the 2 linked-lists
        
        head = p;
        p = p->next;

        while(p != NULL && q != NULL) {
            head->next = q;
            q = q->next;

            head = head->next;

            head->next = p;
            p = p->next;

            head = head->next;
        }
        while(p != NULL) {
            head->next = p;
            p = p->next;
            head = head->next;
        }

        while(q != NULL) {
            head->next = q;
            q = q->next;
            head = head->next;
        }
    }
};