/*
Flatten Binary Tree to Linked ListOct 14 '127105 / 21371

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Hints:

If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
    void flatten(TreeNode *root) {
        TreeNode *tail = NULL;
        preOrder(root, tail);
    }
    
    void preOrder(TreeNode *node, TreeNode *&tail) {
        if(node) {
            if(tail) {
                tail->right = node;
                tail->left = NULL;
            }
            tail = node;
            TreeNode *tmp = node->right;
            preOrder(node->left, tail);
            preOrder(tmp, tail);
        }
    }
};
//post-order traverse is more elegant
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *tail = NULL;
        postOrder(root, tail);
    }
    
    void postOrder(TreeNode *node, TreeNode *&tail) {
        if(node) {
            postOrder(node->right, tail);
            postOrder(node->left, tail);
            node->left = NULL;
            node->right = tail;
            tail = node;
        }
    }
};
//transplant the left sub-tree to the right, then recursive call flatten.
class Solution {
public:
    void flatten(TreeNode *root) {
        if(!root) return;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if(left) {
            root->left = NULL;
            root->right = left;
            TreeNode *rightmost = left;
            while(rightmost->right) rightmost = rightmost->right;
            rightmost->right = right;
        }
        flatten(root->right);
    }
};
//first apply flatten to left and right sub-tree, then adjust the order
class Solution {
public:
    void flatten(TreeNode *root) {
        flat(root);
    }
    TreeNode *flat(TreeNode *node) {
        if(!node) return NULL;
        TreeNode *leftright = flat(node->left);
        TreeNode *rightright = flat(node->right);
        if(node->left) {
            leftright->right = node->right;
        	node->right = node->left;
        	node->left = NULL;
        }
        if(rightright) return rightright;
        if(leftright) return leftright;
        return node;
    }
};
//non-recursive solution
class Solution {
public:
    void flatten(TreeNode *root) {
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while(cur) {
        	while(cur->left) {
        		if(cur->right) stk.push(cur->right);
        		cur->right = cur->left;
        		cur->left = NULL;
        		cur = cur->right;
        	}
        	if(!cur->right && !stk.empty()) {
        		cur->right = stk.top();
        		stk.pop();
        	}
        	cur = cur->right;
        }
    }
};
//like Morris Traversal
class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while(cur) {
            if(cur->left) {
                TreeNode *tmp = cur->left;
                while(tmp->right) tmp = tmp->right;
                tmp->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};