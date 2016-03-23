/*
Maximum Depth of Binary TreeSep 30 '126343 / 9043

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
/**
 * Definition for binary tree
 *  * struct TreeNode {
 *   *     int val;
 *    *     TreeNode *left;
 *     *     TreeNode *right;
 *      *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if(!root) return 0;
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int d=1;
        while(q.size()>1) {
            TreeNode *cur = q.front();
            q.pop();
            if(!cur) {
                d++;
                q.push(NULL);
                continue;
            }
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return d;
    }
};

class Solution {
    public:
        int maxDepth(TreeNode *root) {
            if(!root) return 0;
            root->val = 1;

            queue<TreeNode *> Q;
            TreeNode *node;
            Q.push(root);
            while(!Q.empty()) {
                node = Q.front();
                Q.pop();
                if(node->left) {
                    node->left->val = node->val+1;
                    Q.push(node->left);
                }
                if(node->right) {
                    node->right->val = node->val+1;
                    Q.push(node->right);
                }
            }
            return node->val;
        }
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        queue<TreeNode *> q;
        queue<int> dq;
        q.push(root);
        dq.push(1);
        int d;
        while(!q.empty()) {
            TreeNode *cur = q.front();
            d = dq.front();
            q.pop();
            dq.pop();
            if(cur->left) {
                q.push(cur->left);
                dq.push(d+1);
            }
            if(cur->right) {
                q.push(cur->right);
                dq.push(d+1);
            }
        }
        return d;
    }
};
