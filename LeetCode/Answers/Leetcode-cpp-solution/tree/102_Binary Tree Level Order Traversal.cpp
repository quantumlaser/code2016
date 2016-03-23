/*
Binary Tree Level Order TraversalSep 29 '125832 / 14746

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

*/
void printLevel(BinaryTree *p, int level) {
    if (!p) return;
    if (level == 1) {
        cout << p->data << " ";
    } else {
        printLevel(p->left, level-1);
        printLevel(p->right, level-1);
    }
}

void printLevelOrder(BinaryTree *root) {
    int height = maxHeight(root);
    for (int level = 1; level <= height; level++) {
        printLevel(root, level);
        cout << endl;
    }
}

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > rst;
        traverse(root, rst, 1);
        return rst;
    }
    void traverse(TreeNode *root, vector<vector<int> > &rst, int level) {
        if(!root) return;
        if(level > rst.size()) rst.push_back(vector<int>());
        rst[level-1].push_back(root->val);
        traverse(root->left, rst, level+1);
        traverse(root->right, rst, level+1);
    }
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > rst;
        vector<int> ivec;
        if(!root) return rst;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1) {
            TreeNode *cur = q.front();
            q.pop();
            if(!cur) {
               rst.push_back(ivec); 
                ivec.clear();
                q.push(NULL);
                continue;
            }
            ivec.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        rst.push_back(ivec);
        return rst;
    }
};
//non-recursive solution using two queue;
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > rst;
        if(!root) return rst;
        vector<int> ivec;
        queue<TreeNode *> cur_q, next_q;
        cur_q.push(root);
        while(!cur_q.empty()) {
            while(!cur_q.empty()) {
                TreeNode *cur = cur_q.front();
                cur_q.pop();
                ivec.push_back(cur->val);
                if(cur->left) next_q.push(cur->left);
                if(cur->right) next_q.push(cur->right);
            }
            rst.push_back(ivec);
            ivec.clear();
            cur_q.swap(next_q);
        }
        return rst;
    }
};
//non-recursive solution using two int
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > rst;
        if(!root) return rst;
        vector<int> ivec;
        queue<TreeNode *> q;
        q.push(root);
        int num_cur=1, num_next=0;
        while(!q.empty()) {
            while(num_cur--) {
                TreeNode *cur = q.front();
                q.pop();  
                ivec.push_back(cur->val);
                if(cur->left) q.push(cur->left), num_next++;
                if(cur->right) q.push(cur->right), num_next++;
            }
            rst.push_back(ivec);
            ivec.clear();
            num_cur = num_next;
            num_next = 0;
        }
        return rst;
    }
};