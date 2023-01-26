// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/

#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q; // For BFS
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        q.push(root);

        while(!q.empty()) {

            int nodes = q.size(); // to hold the no. of nodes at the current level
            
            vector<int> curr_level;
            for(int i = 1; i <= nodes; i++) {
                TreeNode* curr_node = q.front();
                q.pop();
                curr_level.push_back(curr_node->val);

                if(curr_node->left != NULL)
                    q.push(curr_node->left);
                if(curr_node->right != NULL)
                    q.push(curr_node->right);
            }
            ans.push_back(curr_level);
        }

        return ans;
    }
};