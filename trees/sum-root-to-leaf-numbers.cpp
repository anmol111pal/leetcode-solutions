// Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    int sum(TreeNode *root, int num) {
        if(root == NULL)
            return NULL;
        
        num = num * 10 + root->val;
        
        // reached the leaf node
        if(root->left == NULL && root->right == NULL) {
            // num contains the number formed by traversing root to leaf
            return num;
        }

        return sum(root->left, num) + sum(root->right, num);
    }

public:
    int sumNumbers(TreeNode* root) {
        return sum(root, 0);
    }
};