// Link: https://leetcode.com/problems/sort-list/description/

/* Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* merge(ListNode* p1, ListNode* p2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;
        while(p1 && p2) {
            if(p1->val <= p2->val) {
                ptr->next = p1;
                p1 = p1->next;
            }
            else {
                ptr->next = p2;
                p2 = p2->next;
            }

            ptr = ptr->next;
        }

        while(p1) {
            ptr->next = p1;
            p1 = p1->next;
            ptr = ptr->next;
        }
        while(p2) {
            ptr->next = p2;
            p2 = p2->next;
            ptr = ptr->next;
        }

        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)  return head;

        // divide linked list into 2 parts
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *x = head;
        ListNode *y = slow->next;
        slow->next = NULL;

        x = sortList(x); // recursively sorting left part
        y = sortList(y); // recursively sorting right part       

        head = merge(x, y); // merging both the halves
        return head;
    }
};