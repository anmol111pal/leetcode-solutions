// Link: https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if(root == NULL) // no node in tree
            return ans;

        // using level order traversal (BFS)
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            TreeNode *node = NULL;
            for(int i=1; i <= size; i++) {
                node = q.front();
                q.pop();

                if(i == size) {
                    ans.emplace_back(node->val);
                }

                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
        }

        return ans;
    }
};