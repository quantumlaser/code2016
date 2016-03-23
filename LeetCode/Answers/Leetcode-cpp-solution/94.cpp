/*
Binary Tree Inorder TraversalAug 27 '122896 / 6178

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> stk;
        vector<int> rst;
        while(root || !stk.empty()) {
            while(root) {
                stk.push(root);
                root = root->left;
            }
            if(!stk.empty()) {
                root = stk.top();
                stk.pop();
                rst.push_back(root->val);
                root = root->right;
            }
        }
        return rst;
    }
};	