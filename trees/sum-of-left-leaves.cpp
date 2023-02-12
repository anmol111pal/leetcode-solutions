// Link: https://leetcode.com/problems/sum-of-left-leaves/description/

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
            
        return sum(root, false); // passing the false flag bcoz the root isnt the left part
    }

    int sum(TreeNode *root, bool isLeft) {
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL && isLeft)
            return root->val;

        // adding the true flag to the call of left subtree & false to right subtree
        return sum(root->left, true) + sum(root->right, false);
    }
};