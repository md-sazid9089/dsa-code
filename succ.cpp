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

// Function to insert a node in BST
Node* insertion(Node* root, int data) {
    if (root == NULL) return new Node(data);
    if (data < root->data) root->left = insertion(root->left, data);
    else root->right = insertion(root->right, data);
    return root;
}

// Function to find Inorder Successor
Node* findSuccessor(Node* root, int key) {
    Node* successor = NULL;
    while (root) {
        if (key < root->data) {
            successor = root;  // Potential successor
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

// Function to find Inorder Predecessor
Node* findPredecessor(Node* root, int key) {
    Node* predecessor = NULL;
    while (root) {
        if (key > root->data) {
            predecessor = root;  // Potential predecessor
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}

// Driver code
int main() {
    Node* root = NULL;
    root = insertion(root, 5);
    root = insertion(root, 3);
    root = insertion(root, 7);
    root = insertion(root, 2);
    root = insertion(root, 4);
    root = insertion(root, 6);
    root = insertion(root, 8);

    int key = 7;

    Node* suc = findSuccessor(root, key);
    Node* pre = findPredecessor(root, key);

    cout << "Key: " << key << endl;
    cout << "Successor: " << (suc ? to_string(suc->data) : "None") << endl;
    cout << "Predecessor: " << (pre ? to_string(pre->data) : "None") << endl;

    return 0;
}

