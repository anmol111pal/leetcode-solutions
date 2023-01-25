// Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

} Node;

struct Node* reverseList(struct Node *head)
{
    struct Node *prev, *curr, *nextPtr;
    curr=head;
    prev=NULL;
    
    while(curr != NULL) {
        nextPtr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPtr;
    }
    
    return prev;
}