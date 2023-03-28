// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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
private:
    TreeNode* insertNode(TreeNode* root, int x) {
        if(root == NULL) {
            root = new TreeNode(x);
            return root;
        }

        if(x < root->val) {
            root->left = insertNode(root->left, x);
        }

        else {
            root->right = insertNode(root->right, x);
        }

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = NULL;

        for(const int& node: preorder) {
            root = insertNode(root, node);
        }

        return root;
    }
};