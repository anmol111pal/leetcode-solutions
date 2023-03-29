// Link: https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

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

#define True 1
#define False 0
#define OR 2
#define AND 3

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        // reached leaf node having either True or False
        if(root->left == NULL && root->right == NULL) {
            if(root->val == True)
                return true;
            else 
                return false;
        }

        int leftAns = evaluateTree(root->left);
        int rightAns = evaluateTree(root->right);

        if(root->val == AND) {
            root->val = leftAns && rightAns;
            // delete its children
            delete root->left;
            delete root->right;
            root->left = root->right = NULL;
        }

        else if(root->val == OR){
            root->val = leftAns || rightAns;
            // delete its children
            delete root->left;
            delete root->right;
            root->left = root->right = NULL;
        }

        // at the end, root will have either True or False
        return root->val == True;
    }
};