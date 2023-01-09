// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
    
        if(root == NULL)
            return ans;
        
        st.push(root);

        while(!st.empty()) {
            TreeNode* node=st.top();
            st.pop();
            ans.push_back(node->val);

            // inserting right first,bcoz, stack works in LIFO
            if(node->right != NULL)
                st.push(node->right);
            if(node->left != NULL)
                st.push(node->left);
        }

        return ans;
    }
};