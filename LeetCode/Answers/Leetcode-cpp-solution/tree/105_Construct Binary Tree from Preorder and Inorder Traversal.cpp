/*
Construct Binary Tree from Preorder and Inorder TraversalSep 30 '124869 / 14001

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder.begin(), inorder.begin(), inorder.size());
    }

    TreeNode *buildTree(vector<int>::iterator iter1,  vector<int>::iterator iter2, int n) {
    	if(!n) return NULL;
    	TreeNode *parent = new TreeNode(*iter1);
    	int div = find(iter2, iter2+n, *iter1) - iter2;
    	parent->left = buildTree(iter1+1, iter2, div);
    	parent->right = buildTree(iter1+div+1, iter2+div+1, n-div-1);
    	return parent;
    }
};