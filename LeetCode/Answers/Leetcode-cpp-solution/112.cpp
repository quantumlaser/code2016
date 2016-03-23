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
    bool hasPathSum(TreeNode *root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right) return sum==root->val;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);

    }
};
//a non-recursive Solution
typedef struct path_element {
	struct TreeNode *node;
	int level; 
} path_element;

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

bool hasPathSum(TreeNode *root, int sum) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    std::stack<path_element> s;
    std::vector<path_element> v;

    if (!root) {
        return false;
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
                return true;
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
    } // while

    return false;
}