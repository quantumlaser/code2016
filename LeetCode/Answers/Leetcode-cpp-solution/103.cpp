/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > rst;
        if(!root) return rst;
        vector<int> ivec;
        queue<TreeNode *> q;
        q.push(root);
        int num_cur=1, num_next=0;
        bool flag=false;
        while(!q.empty()) {
            while(num_cur--) {
                TreeNode *cur = q.front();
                q.pop();  
                ivec.push_back(cur->val);
                if(cur->left) q.push(cur->left), num_next++;
                if(cur->right) q.push(cur->right), num_next++;
            }
            if(flag) reverse(ivec.begin(), ivec.end());
            flag = !flag;
            rst.push_back(ivec);
            ivec.clear();
            num_cur = num_next;
            num_next = 0;
        }
        return rst;
    }
};