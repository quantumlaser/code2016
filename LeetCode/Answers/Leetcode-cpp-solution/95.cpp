/*
Unique Binary Search Trees IIAug 27 '121302 / 3954

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


OJ's Binary Tree Serialization:

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
*/
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
    
    vector<TreeNode *> generateTrees(int start, int end) {
        if(start > end) return vector<TreeNode *>(1);
        vector<TreeNode *> rst;
        for(int i=start; i<=end; ++i) {
            vector<TreeNode *> leftTrees = generateTrees(start, i-1);
            vector<TreeNode *> rightTrees = generateTrees(i+1, end);
            for(int j=0; j<leftTrees.size(); ++j)
                for(int k=0; k<rightTrees.size(); ++k) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTrees[j];
                    root->right = rightTrees[k];
                    rst.push_back(root);
                }
        }
        return rst;
    }
};