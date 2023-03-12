// Link: https://leetcode.com/problems/linked-list-random-node/description/

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
private:
    ListNode *head;
    int length;

public:
    Solution(ListNode* head) {
        this->head = head;
        length = 0;

        while(head != NULL) {
            length++;
            head = head->next;
        }

        srand(time(0));
    }
    
    int getRandom() {
        int x = rand() % length; // generating a random number between 1 and the length of linked-list

        int i = 1;
        ListNode *ptr = head;

        while(ptr != NULL && i <= x) {
            i++;
            ptr = ptr->next;
        }

        return ptr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */