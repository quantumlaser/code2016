/*
Recover Binary Search TreeSep 1 '124967 / 16821

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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
    void recoverTree(TreeNode *root) {
        TreeNode *pre = new TreeNode(INT_MIN);
        vector<TreeNode *> tvec(2);
        inorder(root, pre, tvec);
        if(tvec[0]) swap(tvec[0]->val, tvec[1]->val);
    }
    void inorder(TreeNode *node, TreeNode *&pre, vector<TreeNode *> &tvec) {
        if(!node) return;
        inorder(node->left, pre, tvec);
        if(node->val <= pre->val ) {
            if(!tvec[0]) tvec[0]=pre;
            tvec[1] = node;
        }
        pre = node;
        inorder(node->right, pre, tvec);
    }
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *cur=root, *pre=NULL, *tmp;
        vector<TreeNode *> tvec(2);
        while(cur) {
            if(!cur->left) {
                if(pre && pre->val>=cur->val) {
                    if(!tvec[0]) tvec[0] = pre;
                    tvec[1] = cur;
                }
                pre = cur;
                cur = cur->right;
                continue;
            }
            tmp = cur->left;
            while(tmp->right && tmp->right!=cur) tmp = tmp->right;
            if(!tmp->right) {
                tmp->right = cur;
                cur = cur->left;
            }
            else {
                tmp->right = NULL;
                if(pre->val >= cur->val) {
                    if(!tvec[0]) tvec[0] = pre;
                    tvec[1] = cur;
                }
                pre = cur;
                cur = cur->right;
            }
        }
        if(tvec[0]) swap(tvec[0]->val, tvec[1]->val);
    }
};