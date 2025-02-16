/*************************************************************************
	> File Name: 13.LC226.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 05:07:00 PM CST
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    swap(root->left, root->right);
    invertTree(root-left);
    invertTree(root->right);
    return root;
    }
};
