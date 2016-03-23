/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> rst;
        if(!root) return rst;
        stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            rst.push_back(node->val);
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);

        }
        return rst;
    }
};