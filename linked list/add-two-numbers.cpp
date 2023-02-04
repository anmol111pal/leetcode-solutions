// Link: https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(-1); // dummy node, actual ans will be appended to this.
        ListNode *ptr = ans;

        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            int sum = carry + l1->val + l2->val;

            if(sum > 9) {
                sum %= 10;
                carry = 1;
            }
            else    
                carry = 0;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1!= NULL) {
            int sum = carry + l1->val;
            if(sum > 9) {
                sum %= 10;
                carry = 1;
            }
            else    
                carry = 0;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l1 = l1->next;
        }

        while(l2 != NULL) {
            int sum = carry + l2->val;
            if(sum > 9) {
                sum %= 10;
                carry = 1;
            }
            else    
                carry = 0;
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            l2 = l2->next;
        }

        // if carry is left, add it to the ans
        if(carry != 0)
            ptr->next = new ListNode(carry);

        return ans->next;
    }
};