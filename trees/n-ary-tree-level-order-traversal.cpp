// Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> bfs; // this will hold the level order traversal

        if(root == NULL)
            return bfs;

        queue<Node *> q;

        q.push(root);

        while(!q.empty()) {
            int n = q.size(); // number of nodes at the current level

            vector<int> curr_level; // this will hold the nodes of the current level
            for(int i = 1; i <= n; i++) {
                Node *node = q.front();
                q.pop();

                curr_level.emplace_back(node->val);

                // enqueue the children of the current node
                if(node->children.size() != 0) {
                    for(Node* child_node: node->children) {
                        q.push(child_node);
                    }
                }
            }

            bfs.emplace_back(curr_level);
        }

        return bfs;
    }
};