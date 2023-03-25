// Link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/

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
private:
    // this function populates the vector with the inorder traversal of the tree
    void inorder(TreeNode *root, vector<int>& arr) {
        if(root == NULL)
            return;
            
        inorder(root->left, arr);
        arr.emplace_back(root->val);
        inorder(root->right, arr);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2, ans;

        inorder(root1, arr1); // will get the inorder of root1 in arr1
        inorder(root2, arr2); // will get the inorder of root2 in arr2

        int i = 0, j = 0;
        while(i < arr1.size() && j < arr2.size()) {
            if(arr1[i] < arr2[j])
                ans.emplace_back(arr1[i++]);
            else
                ans.emplace_back(arr2[j++]);
        }

        while(i < arr1.size())
            ans.emplace_back(arr1[i++]);

        while(j < arr2.size())
            ans.emplace_back(arr2[j++]);

        return ans;
    }
};