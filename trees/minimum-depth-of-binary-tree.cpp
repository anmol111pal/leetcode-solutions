// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

#include <bits/stdc++.h>
using namespace std;

/* Definition for a binary tree node.*/
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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        // if depth of right subtree is 0, consider leftDepth
        if(rightDepth == 0) 
            return 1 + leftDepth;
            
        // if the depth of left subtree is 0, consider rightDepth
        if(leftDepth == 0)
            return 1 + rightDepth;

        return 1 + min(leftDepth, rightDepth);
    }
};