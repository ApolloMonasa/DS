/*************************************************************************
	> File Name: 10.LC105.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 04:07:48 PM CST
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0) return NULL;
    int pos = 0;//记录root在中序遍历里面的位置
    while (inorder[pos] != preorder[0]) pos++;
    TreeNode *root = new TreeNode(preorder[0]);
    vector<int> preArr, inArr;
    for (int i = 1; i <= pos; i++) preArr.push_back(preorder[i]);
    for (int i = 0; i < pos; i++) inArr.push_back(inorder[i]);
    //得到了左字树的前中遍历
    root->left = buildTree(preArr, inArr);
    preArr.clear();
    inArr.clear();
    for (int i = pos + 1; i < preorder.size(); i++) preArr.push_back(preorder[i]);
    for (int i = pos + 1; i < preorder.size(); i++) inArr.push_back(inorder[i]);
    root->right = buildTree(preArr, inArr);
    return root;
    }
};
