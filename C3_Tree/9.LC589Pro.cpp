/*************************************************************************
	> File Name: 9.LC589Pro.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Feb 2025 12:28:30 AM CST
 ************************************************************************/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void __preorder(Node *root, vector<int> &ans) {
        if(!root) return ;
        ans.push_back(root->val);
        for(auto x : root->children) {
            __preorder(x, ans);
        }
        return ;
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        __preorder(root, ans);
        return ans;
    }
};
