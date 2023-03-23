// Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int max_sum_level = -1, max_sum = INT_MIN;
        int curr_level = 1; // maintain a counter for the level

        while(!q.empty()) {
            int curr_level_sum = 0; // sum of nodes at the current level

            int n = q.size(); // number of nodes at the current level

            for(int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();

                curr_level_sum += node->val;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            // checking if the sum at current level is the max so far
            if(curr_level_sum > max_sum) {
                max_sum = curr_level_sum;
                max_sum_level = curr_level;
            }

            curr_level++;
        }

        return max_sum_level;
    }
};