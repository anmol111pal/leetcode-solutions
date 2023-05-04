// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        stack<TreeNode*> st;
        st.push(root);

        TreeNode *dummy = new TreeNode(-1);
        TreeNode *ptr = dummy;

        while(!st.empty()) {
            TreeNode *node = st.top();
            st.pop();

            // flattening
            ptr->right = node;
            ptr->left = NULL;
            ptr = ptr->right;

            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }

        root = dummy->right;
    }
};