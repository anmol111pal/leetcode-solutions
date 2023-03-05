// Link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        
        if(root == NULL)
            return -1;
        
        q.push(root);
        
        priority_queue<long long> pq; // to store the sum of nodes at every level
        
        while(!q.empty()) {
            int n = q.size();
            
            long long sum = 0;
            for(int i = 1; i <= n; i++) {
                TreeNode *node = q.front();
                q.pop();
                
                sum += node->val;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right); 
            }
            
            pq.push(sum); // pushing the sum of every level to priority queue
        }
        
        int i = 1;
        
        while(!pq.empty() && i < k) {
            i++;
            pq.pop();
        }
        
        if(pq.empty()) // tree had fewer than k levels
            return -1;
        
        return pq.top();        
    }
};
