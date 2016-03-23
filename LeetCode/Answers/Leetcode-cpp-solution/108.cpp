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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int n = num.size();
        if(!n) return NULL;
        int mid = n/2;
        vector<int> a(num.begin(), num.begin()+mid);
        vector<int> b(num.begin()+mid+1, num.end());
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(a);
        root->right = sortedArrayToBST(b);
        return root;
    }
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size());
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num, int b, int e) {
        if(b >= e) return NULL;
        int m = b + (e-b)/2;
        TreeNode *root = new TreeNode(num[m]);
        root->left = sortedArrayToBST(num, b, m);
        root->right = sortedArrayToBST(num, m+1, e);
        return root;
    }
};