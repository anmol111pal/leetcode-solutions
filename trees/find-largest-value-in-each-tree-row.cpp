// Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            const int n = q.size();
            int max_val = INT_MIN;

            for(int i = 0; i < n; i++) {
                const TreeNode *node = q.front();
                q.pop();

                max_val = max(max_val, node->val);

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            ans.emplace_back(max_val);
        }

        return ans;
    }
};