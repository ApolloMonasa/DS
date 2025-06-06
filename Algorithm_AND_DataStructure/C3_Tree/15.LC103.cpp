/*************************************************************************
	> File Name: 15.LC103.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 05:25:51 PM CST
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
    void dfs(TreeNode *root, int k, vector<vector<int>> &ans) {
        if(!root) return ;
        if(k == ans.size()) ans.push_back(vector<int>());
        ans[k].push_back(root->val);
        dfs(root->left, k+1, ans);
        dfs(root->right, k+1, ans);
        return ;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(!root) return vector<vector<int>> ();
    vector<vector<int>> ans;
    dfs(root, 0, ans);
    for(int i = 1; i < ans.size(); i+=2){
        int l = 0, r = ans[i].size()-1;
        while(l<r){
            swap(ans[i][l], ans[i][r]);
            l++;
            r--;
        }
    }
    return ans;
    }
};
