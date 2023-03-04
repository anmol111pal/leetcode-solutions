// Link: https://leetcode.com/problems/path-sum/description/

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
private:
    bool checkSum(TreeNode *root, int sum, int target) {
        if(root == NULL)
            return false;
        
        sum += root->val;

        // reached the leaf node
        if(root->left == NULL && root->right == NULL) { 
            if(sum == target) // after reaching leaf, we found the path sum
                return true;
        
            if(sum != target) // after reaching leaf, didn't find the path sum
                return false;
        }

        // any one of the subtrees would return the ans (true / false)
        return checkSum(root->left, sum, target) || checkSum(root->right, sum, target);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkSum(root, 0, targetSum);
    }
};