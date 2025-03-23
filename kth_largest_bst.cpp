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
Node* insertion(Node* root, int data) {
    if (root == NULL) return new Node(data);
    if (data < root->data) root->left = insertion(root->left, data);
    else root->right = insertion(root->right, data);
    return root;
}
void KthLargestUtil(Node* root, int &K, int &result) {
    if (root == NULL || K <= 0) return;
    KthLargestUtil(root->right, K, result);
    K--;
    if (K == 0) {
        result = root->data;
        return;
    }
    KthLargestUtil(root->left, K, result);
}
int KthLargest(Node* root, int K) {
    int result = -1;
    KthLargestUtil(root, K, result);
    return result;
}
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
    cout << K << "-th largest element: " << KthLargest(root, K) << endl;
    return 0;
}

