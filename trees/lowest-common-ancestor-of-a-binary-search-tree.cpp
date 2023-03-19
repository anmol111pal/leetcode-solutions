// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node.  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
            return root;

        // both lie on the right subtree
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // both lie on the left subtree
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        // either of p & q are on the two sides of root
        return root;
    }
};