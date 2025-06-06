/*************************************************************************
	> File Name: 16.LCR143.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 06:30:32 PM CST
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
    bool match_one(TreeNode* A, TreeNode* B) {
        if(A == NULL) return B == NULL;
        if(B == NULL) return true;
        if(A->val != B->val) return false;
        return match_one(A->left, B->left) &&  match_one(A->right, B->right);
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
    if(A == NULL) return false;
    if(B == NULL) return false;
    if(A->val == B->val && match_one(A, B)) return true;
    return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    return false;
    }
};
