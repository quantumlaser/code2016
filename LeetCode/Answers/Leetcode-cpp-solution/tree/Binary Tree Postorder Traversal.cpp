/*
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
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
    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode *pre = NULL, *node = root;
        stack<TreeNode *> stk;
        vector<int> rst;
        while(!stk.empty() || node) {
            if(node) {
                stk.push(node);
                node = node->left;
            }
            else {
                node = stk.top();
                if(!node->right || pre==node->right) {
                    stk.pop();
                    pre = node;
                    rst.push_back(node->val);
                    node = NULL;
                }
                else node = node->right;
            }
        }
        return rst;
    }
};