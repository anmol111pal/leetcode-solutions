// Link: https://leetcode.com/problems/odd-even-linked-list/description/

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
    int countNodes(ListNode* head) {
        int c = 0;
        while(head != NULL) {
            c++;
            head = head->next;
        }
        return c;
    }

public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return NULL;

        ListNode *dummy = new ListNode(-1); // dummy node

        ListNode *p1 = head, *curr = head, *p2 = dummy;
        int n = countNodes(head), i = 1;

        while(i <= n) {
            p2->next = curr->next; // adding the node at even index into dummmy LL

            if(curr == NULL || curr->next == NULL) {
                break;
            }

            else if(curr->next != NULL) {
                p1->next = curr->next->next; // skipping the even-index node
                p1 = p1->next; // jumping to the next odd index node
                curr = curr->next;
                p2 = p2->next;
            }

            i += 2;
        }

        // connecting the (dummy) LL having nodes at even indices
        ListNode *ptr = head;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = dummy->next;        

        return head;
    }
};