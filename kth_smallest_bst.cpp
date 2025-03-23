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

// Inorder traversal to find K-th smallest element
void KthSmallestUtil(Node* root, int &K, int &result) {
    if (root == NULL || K <= 0) return;

    // Left Subtree (Smaller elements first)
    KthSmallestUtil(root->left, K, result);

    // Process current node
    K--;
    if (K == 0) {
        result = root->data;
        return;
    }

    // Right Subtree
    KthSmallestUtil(root->right, K, result);
}

// Wrapper function
int KthSmallest(Node* root, int K) {
    int result = -1;
    KthSmallestUtil(root, K, result);
    return result;
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

    int K = 3;
    cout << K << "-th smallest element: " << KthSmallest(root, K) << endl;
    return 0;
}
