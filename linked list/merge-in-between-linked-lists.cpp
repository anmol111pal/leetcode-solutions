// Link: https://leetcode.com/problems/merge-in-between-linked-lists/description/

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *prevPtr = list1;
        int i = 0;

        while(prevPtr && prevPtr->next && i < a-1) {
            prevPtr = prevPtr->next;
            i++;
        }
        // prevPtr points to the node just before node with val = a

        ListNode *nextPtr = prevPtr;

        while(nextPtr && i < b) {
            nextPtr = nextPtr->next;
            i++;
        }
        // nextPtr points to the node with val = b
        
        // now append list2 after prevPtr
        prevPtr->next = list2;
        
        // and append nextPtr->next after list2
        ListNode *ptr = list2;
        while(ptr && ptr->next) // reach to the last node of list2
            ptr = ptr->next;

        ptr->next = nextPtr->next;

        return list1;
    }
};