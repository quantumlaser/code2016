/*
Balanced Binary TreeOct 9 '123247 / 7909

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode *root) {
        if(!root) return true;
        if(abs(maxDepth(root->left) - maxDepth(root->right)) >1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
    
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(!root) return true;
        return depth(root) >0;
        
    }    
    int depth(TreeNode *root) {
        if(!root) return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        if(l<0||r<0||abs(l-r)>1) return -1;
        return max(l, r) + 1;
    }
};

class Solution{ 
public:
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if(l==-1 || r==-1 || abs(l-r)>1) return -1;
        return max(l,r) + 1;
    }
    bool isBalanced(TreeNode *root) {
        return maxDepth(root)!=-1;
    }
};