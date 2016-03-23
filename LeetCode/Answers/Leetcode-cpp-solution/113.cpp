/*
Path Sum IIOct 14 '126392 / 17591

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > rst;
        vector<int> ivec;
        findSub(root, sum, rst, ivec);
        return rst;
    }
    void findSub(TreeNode *root, int sum, vector<vector<int> > &vvec, vector<int> &ivec) {
        if(!root) return;
        ivec.push_back(root->val);
        if(!root->left && !root->right && root->val==sum) {
            vvec.push_back(ivec);
            ivec.pop_back();
            return;
        }
        if(root->left) findSub(root->left, sum-root->val, vvec, ivec);
        if(root->right) findSub(root->right, sum-root->val, vvec, ivec);
        ivec.pop_back();
    }

    void findSub2(TreeNode *node, int sum, vector<vector<int> > &rst, vector<int> v) {
        if(!node) return;
        v.push_back(node->val);
        if(!node->left && !node->right && node->val==sum) {
            rst.push_back(v);
        }
        findSub2(node->left, sum-node->val, rst, v);
        findSub2(node->right, sum-node->val, rst, v);
        v.pop_back();
    }
};


typedef struct path_element {
struct TreeNode *node;
int level; } path_element;

void addNodeToPath(std::vector<path_element> *path, path_element element)
{
    while (!path->empty()) {
        if (path->back().level >= element.level) {
            path->pop_back();
        } else {
            break;
        }
    }
    path->push_back(element);
}

bool verifyPathSum(std::vector<path_element> *path, int sum) {
    int s = 0;
    std::vector<path_element>::iterator it;

    for (it = path->begin(); it != path->end(); it++) {
        s += it->node->val;
    }

    return (s == sum);
}

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    std::stack<path_element> s;
    std::vector<path_element> v;
    std::vector<vector<int> > multi_pathes;

    if (!root) {
        return multi_pathes;
    }

    path_element r;
    r.node = root;
    r.level = 1;
    s.push(r);
    v.push_back(r);

    while (!s.empty()) {
        path_element tmp, p = s.top();
        s.pop();

        addNodeToPath(&v, p);

        if (!(p.node->right) && !(p.node->left)) {
            if (verifyPathSum(&v, sum)) {
                std::vector<int> one_path;
                std::vector<path_element>::iterator it;
                for (it = v.begin(); it != v.end(); it++) {
                    one_path.push_back(it->node->val);
                }
                multi_pathes.push_back(one_path);
            }
            continue;
        }

        if ((p.node)->right) {
            tmp.node = (p.node)->right;
            tmp.level = p.level + 1;
            s.push(tmp);
        }
        if ((p.node)->left) {
            tmp.node = (p.node)->left;
            tmp.level = p.level + 1;
            s.push(tmp);
        }
    }

    return multi_pathes;
}