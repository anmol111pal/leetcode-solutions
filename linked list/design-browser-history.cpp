// Link: https://leetcode.com/problems/design-browser-history/description/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string val; // this will hold the current page's URL
    Node* next, *prev;

    Node(): val(""), prev(NULL), next(NULL) {}
    Node(string x): val(x), prev(NULL), next(NULL) {} 
};

class BrowserHistory {
private:
    Node *curr;    

public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node *node = new Node(url);
        curr->next = node;
        node->prev = curr;

        curr = node; // visited the new URL
    }
    
    string back(int steps) {
        while(curr->prev != NULL && steps > 0) {
            steps--;
            curr = curr->prev;
        }

        return curr->val;
    }
    
    string forward(int steps) {
        while(curr->next != NULL && steps > 0) {
            steps--;
            curr = curr->next;
        }

        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */