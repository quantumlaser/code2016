/**
 * Definition for binary tree
 * struct TNode {
 *      int val;
 *      TNode *left;
 *      TNode *right;
 *      TNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void preorder(TNode *root)
{
    if(!root) {
        visit(root);
        preorder(root->left);
        preorder(root->right);
    }
}

void preorder2(TNode *root)
{
    Stack S;
    while(!root || !S.empty()) {
        while(!root) {
            visit(root);
            S.push(root);
            root = root->left;
        }
        if(!S.empty()) {
            root = S.pop();
            root = root->right;
        }
    }
}

void preorder3(TNode *root) 
{
    if(!root) {
        Stack S;
        S.push(root);
        if(!S.empty()) {
            root = S.pop();
            S.push(root->right);
            S.push(root->left);
        }
    }
}

void inorder(TNode *root)
{
    Stack S;
    while(!root || !S.empty) {
        while(!root) {
            S.push(root);
            root = root->left;
        }
        if(!S.empty()) {
            root = S.pop();
            visit(root);
            root = root->right;
        }
    }
}

void levelorder(TNode *root) {
    Queue Q;
    TNode *node;
    Q.push(root);

    while(!Q.empty()) {
        node = Q.front();
        visit(node);

        if(!node->left) Q.push(node->left);
        if(!node->right) Q.push(node->right);
    }
}

