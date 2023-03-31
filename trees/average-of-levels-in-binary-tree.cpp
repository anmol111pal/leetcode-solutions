// Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            double total = 0.0;

            for(int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                
                total += node->val;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            double avg = total / n; // avg of noeds of current level
            ans.emplace_back(avg);
        }

        return ans;
    }
};