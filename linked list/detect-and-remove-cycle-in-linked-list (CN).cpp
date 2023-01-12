// Link: https://www.codingninjas.com/codestudio/problems/detect-and-remove-cycle_920523?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;
// Following is the class structure of the Node class:
class Node
{
public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
    }
};

bool detectAndRemoveCycle(Node* head)
{
    Node* slow=head, *fast=head;
    while(fast != NULL && fast->next != NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) // cycle detected
            break;
    }
    // loop starts at the head only
    if(slow==head) {
        while(fast->next != slow)
            fast=fast->next;
        fast->next=NULL;
        return true; // cycle was present
    }
    
    else if(slow == fast) {
        Node *p1=head, *p2=slow;
        while(p1->next != p2->next) {
            p1=p1->next;
            p2=p2->next;
        }
        p2->next=NULL;
        return true; // cycle was present
    }
    else
        return false; // no cycle was present
}