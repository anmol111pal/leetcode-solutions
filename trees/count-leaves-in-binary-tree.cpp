// Link: https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1?page=1&category[]=Tree&curated[]=1&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

/* Should return count of leaves. For example, return
    value should be 2 for following tree.
        10
     /     \ 
   20       30 
*/

int countLeaves(Node* root) {
    if(root == NULL)
        return 0;
    
    // condition for leaf node
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    return countLeaves(root->left) + countLeaves(root->right);
}