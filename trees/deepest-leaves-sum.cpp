// Link: https://leetcode.com/problems/deepest-leaves-sum/description/

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
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        // compute the sum of nodes at each level,
        // at the end of the BFS traversal, this will have the sum of deepest leaves (nodes)
        int curr_level_sum = 0;

        while(!q.empty()) {
            curr_level_sum = 0; // reset this to get the sum of the curr level
            int n = q.size();

            for(int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();

                curr_level_sum += node->val;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }

        // at the end, curr_level_sum will have the sum of nodes at the last level

        return curr_level_sum;
    }
};