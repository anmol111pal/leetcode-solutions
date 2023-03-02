// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

/**
Definition for a binary tree node.  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;

        if(root == p || root == q)
            return root;

        // check in the left subtree
        TreeNode *left = lowestCommonAncestor(root->left, p, q);

        // check in the right subtree
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL) // LCA not found in left subtree 
            return right;

        if(right == NULL) // LCA not found in right subtree
            return left;
        
        return root;
    }
};