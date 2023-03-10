// Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/

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
    vector<int> preorder(Node* root) {
        vector<int> ans;

        if(root == NULL)
            return ans;

        stack<Node*> st;
        
        st.push(root);

        while(!st.empty()) {
            Node *node = st.top();
            st.pop();

            ans.emplace_back(node->val);

            if(node->children.size() != 0) {
                for(int i = node->children.size()-1; i >= 0; i--) {
                    st.push(node->children[i]);
                }
            }
        }

        return ans;
    }
};