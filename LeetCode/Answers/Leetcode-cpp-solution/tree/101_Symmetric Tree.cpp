/*
Symmetric TreeSep 24 '127123 / 14917

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.

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
        bool isSymmetric(TreeNode *root) {
            if(!root) return true;
            queue<TreeNode *> q;
            q.push(root->left);
            q.push(root->right);
            TreeNode *l, *r;
            while(!q.empty()) {
                l = q.front();
                q.pop();
                r = q.front();
                q.pop();
                if(l==NULL && r==NULL) continue;
                if(l==NULL || r==NULL || l->val != r->val) return false;
                q.push(l->left);
                q.push(r->right);
                q.push(l->right);
                q.push(r->left);
            }
            return true;
        }
};

class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            if(!root) return true;
            return helper(root->left, root->right);

        }
    private:
        bool helper(TreeNode *a, TreeNode *b) {
            if(a==NULL && b==NULL) return true;
            if(a==NULL || b==NULL) return false;
            if(a->val != b->val) return false;
            return helper(a->left, b->right) && helper(a->right, b->left);
        }
};
