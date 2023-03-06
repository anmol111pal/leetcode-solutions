// Link: https://leetcode.com/problems/add-two-numbers-ii/description/

#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list.  */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    // function to reverse a linked list
    ListNode* reverse(ListNode *head) {
        ListNode *prevPtr = NULL, *curr = head, *nextPtr = NULL;

        while(curr != NULL) {
            nextPtr = curr->next;

            curr->next = prevPtr;
            prevPtr = curr;
            curr = nextPtr;
        }

        return prevPtr;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(-1); // dummy node, actual sum will be appended to this node

        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode *ptr = ans;
        int carry = 0;

        while(l1 != NULL || l2 != NULL) {
            int x = l1 == NULL ? 0: l1->val;
            int y = l2 == NULL ? 0: l2->val;

            int sum = x + y + carry;

            carry = sum / 10;
            sum %= 10;

            ptr->next = new ListNode(sum);
            ptr = ptr->next;

            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }

        // if carry is left after all the addition is done
        if(carry != 0) {
            ptr->next = new ListNode(carry);
            ptr = ptr->next;
        }

        ans->next = reverse(ans->next);
        return ans->next;
    }
};