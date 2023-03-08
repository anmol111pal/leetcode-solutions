// Link: https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root) {
    vector<int> ans; // level order traversal
    
    queue<Node*> q;
    if(root == NULL)
        return ans;
    
    q.push(root);
    int x = 1; // level
    
    while(!q.empty()) {
        const int n = q.size();
        vector<int> level;
        for(int i = 0; i < n; i++) {
            const Node *node = q.front();
            q.pop();
            level.emplace_back(node->data);
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        
        if(x % 2 != 0) // for odd levels (spiral form)
            reverse(level.begin(), level.end());
        for(const int& elem: level)
            ans.emplace_back(elem);
            
        x++;
    }
    
    return ans;
}