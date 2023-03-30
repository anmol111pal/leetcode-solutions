// Link: https://leetcode.com/problems/next-greater-node-in-linked-list/description/

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
    ListNode* reverseList(ListNode *head) {
        ListNode *prev = NULL, *curr = head, *nextPtr = NULL;

        while(curr != NULL) {
            nextPtr = curr->next;

            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }

        return prev;
    }

    int countNodes(ListNode *head) {
        int count = 0;
        while(head != NULL) {
            count++;
            head = head->next;
        }

        return count;
    }

public:
    vector<int> nextLargerNodes(ListNode* head) {
        int n = countNodes(head);
        vector<int> ans(n);

        ListNode *ptr = reverseList(head);

        stack<int> st;
        st.push(0);

        int i = n - 1;
        for(; ptr != NULL; ptr = ptr->next) {
            int curr = ptr->val;

            while(!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // no greater element found
            if(st.empty()) {
                ans[i--] = 0;
                st.push(curr);
                continue;
            }

            else {
                ans[i--] = st.top();
                st.push(curr);
                continue;
            }

            if(st.top() > curr) {
                ans[i--] = st.top();
                st.push(curr);
                continue;
            }
            
        }

        return ans;
    }
};