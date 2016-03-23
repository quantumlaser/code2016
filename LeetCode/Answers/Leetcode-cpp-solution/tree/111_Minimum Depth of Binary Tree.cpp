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
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int rst = INT_MAX;
        if(root->left) rst = minDepth(root->left);
        if(root->right) rst = min(rst, minDepth(root->right));
        return rst + 1;
    }
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        int d = INT_MAX;
        if(!root) return 0;
        minDepthSub(root, d, 1);
        return d;
    }
    void minDepthSub(TreeNode *node, int &d, int l) {
        if(!node) return;
        if(!node->left && !node->right) {
            d = min(d, l);
            return;
        }
        minDepthSub(node->left, d, l+1);
        minDepthSub(node->right, d, l+1);
    }
};
//3 non-recursive solution,one use NULL pointer to seperate different level, one uses two queue(a depth queue), the last also uses two queue(to swap).
//A solution using only one queue and two integer to seperate levels is refered to 102.cpp
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        queue<TreeNode *> q;
        int d=1;
        TreeNode *cur;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            if(!cur->left && !cur->right) return d;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            if(!q.front()) {
                d++;
                q.pop();
                q.push(NULL);
            }
        }
    }
};
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> q;
        queue<int> dep_queue;
        q.push(root);
        dep_queue.push(1);
        int depth = 1;
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            depth = dep_queue.front();
            dep_queue.pop();
            if(front->left ==NULL && front->right==NULL) {
                return depth;
            }
            if (front->left != NULL) {
                q.push(front->left);
                dep_queue.push(depth+1);
            }
            if (front->right != NULL) {
                q.push(front->right);
                dep_queue.push(depth+1);
            }
        }
        return 0;
    }
};

class Solution {
public:
int minDepth(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (!root) return 0;
    int depth=1;
    queue <TreeNode *> current;
    queue <TreeNode *> next;
    current.push(root);
    while (!current.empty())
    {
        while (!current.empty())
        {
            TreeNode *n = current.front();
            current.pop();
            if (n->left==NULL && n->right == NULL) return depth;
            if (n->left) next.push(n->left);
            if (n->right) next.push(n->right);
        }
        queue <TreeNode *> t;
        current = next;
        next = t;
        depth+=1;

    }
    return depth;
}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int d = 1, cur = 1, next = 0;
        while(!q.empty()) {
            while(cur--) {
                TreeNode *tmp = q.front();
                q.pop();
                if(!tmp->left && !tmp->right) return d;
                if(tmp->left) q.push(tmp->left), next++;
                if(tmp->right) q.push(tmp->right), next++;
            }
            cur = next;
            next = 0;
            d++;
        }
    }
};

