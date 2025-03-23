#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
void inorder(Node* root, vector<int> &arr) {
    if (root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
bool isBST_Inorder(Node* root) {
    vector<int> arr;
    inorder(root, arr);
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= arr[i - 1]) return false;
    }
    return true;
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    if (isBST_Inorder(root))
        cout << "The tree is a BST\n";
    else
        cout << "The tree is NOT a BST\n";

    return 0;
}

