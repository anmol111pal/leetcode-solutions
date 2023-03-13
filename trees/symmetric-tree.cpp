// Link: https://leetcode.com/problems/symmetric-tree/description/

#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node.  */
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL)
            return true;

        if((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
            
        if(p->val != q->val)
            return false;
        
        return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};