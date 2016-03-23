/*
Construct Binary Tree from Inorder and Postorder TraversalSep 30 '124493 / 12665

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder.begin(), postorder.begin(), inorder.size());
    }

    TreeNode *buildTree(vector<int>::iterator iter1, vector<int>::iterator iter2, int n) {
    	if(!n) return NULL;
    	int val = *(iter2+n-1);
    	TreeNode *parent = new TreeNode(val);
    	int div = find(iter1, iter1+n, val) - iter1;
    	parent->left = buildTree(iter1, iter2, div);
    	parent->right = buildTree(iter1+div+1, iter2+div, n-div-1);
    	return parent;
    }
};