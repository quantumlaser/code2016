/*
Binary Tree Maximum Path SumNov 8 '122718 / 9853

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6.*/
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
    int maxPathSum(TreeNode *root) {
        int maxsum = INT_MIN, tsum;
        helper(root, tsum, maxsum);
        return maxsum;
    }
    void helper(TreeNode *node, int &tsum, int &maxsum) {
        if(!node) {
            tsum = 0;
            return;
        }
        int left, right;
        helper(node->left, left, maxsum);
        helper(node->right, right, maxsum);
        tsum = max(node->val, max(left, right) + node->val);
        maxsum = max(maxsum, max(tsum, node->val+left+right));
    }
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
    
    int dfs(TreeNode *node, int &maxSum) {
        if(!node) return 0;
        int left = dfs(node->left, maxSum);
        int right = dfs(node->right, maxSum);
        int tsum = max(node->val, max(left, right)+node->val);
        maxSum = max(maxSum, max(tsum, left+right+node->val));
        return tsum;
    }
};