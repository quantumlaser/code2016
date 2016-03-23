/*
Sum Root to Leaf NumbersFeb 193261 / 9218

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode *root) {
        return preOrder(root, 0);
    }
    
    int preOrder(TreeNode *p, int pre) {
        if(!p) return 0;
        pre  = 10*pre + p->val;
        if(!p->left && !p->right) return pre;
        else return preOrder(p->left, pre) + preOrder(p->right, pre);
    }
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        stack<TreeNode *> stk;
        int sum = 0;
        while(root || !stk.empty()) {
            if(root) {
                stk.push(root);
                if(!root->left && !root->right) sum+= root->val;
                else if(root->left) root->left->val += root->val * 10;
                root = root->left;
            }
            else {
                root = stk.top();
                stk.pop();
                if(root->right) root->right->val += root->val * 10;
                root = root->right;
            }
        }
        return sum;
    }
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        if(root) {
            stack<TreeNode *> stk;
            stk.push(root);
            while(!stk.empty()) {
                TreeNode *node = stk.top();
                stk.pop();
                if(!node->left && !node->right) sum+=node->val;
                if(node->right) {
                    node->right->val += node->val*10;
                    stk.push(node->right);
                }
                if(node->left) {
                    node->left->val += node->val*10;
                    stk.push(node->left);
                }
            }
        }
        return sum;
    }
};




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

int computeRootLeafSum(std::vector<path_element> *path) {
    int s = 0, number = 0;
    std::vector<path_element>::iterator it;

    for (it = path->begin(); it != path->end(); it++) {
        s = number + it->node->val;
        number = s * 10;
    }

    return s;
}

int sumNumbers(TreeNode *root) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    std::stack<path_element> s;
    std::vector<path_element> v;
    int sum = 0;

    if (!root) {
        return sum;
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
            sum += computeRootLeafSum(&v);
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

    return sum;
}