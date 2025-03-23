#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);

    TreeNode* cur = root;
    while (true) {
        if (val < cur->val) {
            if (cur->left != NULL)
                cur = cur->left;
            else {
                cur->left = new TreeNode(val);
                break;
            }
        } else {
            if (cur->right != NULL)
                cur = cur->right;
            else {
                cur->right = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

TreeNode* findLastRight(TreeNode* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

TreeNode* helper(TreeNode* root) {
    if (root->left == NULL) return root->right;
    if (root->right == NULL) return root->left;

    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return NULL;

    if (root->val == key) return helper(root);

    TreeNode* dummy = root;
    while (root != NULL) {
        if (root->val > key) {
            if (root->left != NULL && root->left->val == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if (root->right != NULL && root->right->val == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;

    root = insertIntoBST(root, 50);
    root = insertIntoBST(root, 30);
    root = insertIntoBST(root, 70);
    root = insertIntoBST(root, 20);
    root = insertIntoBST(root, 40);
    root = insertIntoBST(root, 60);
    root = insertIntoBST(root, 80);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);

    cout << "Inorder traversal after deleting 50: ";
    inorder(root);
    cout << endl;

    return 0;
}
