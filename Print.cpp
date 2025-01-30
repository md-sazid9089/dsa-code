#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Insert at the first position
Node* insertAtFirst(Node* head, int value) {
    Node* new_node = new Node(value);
    new_node->next = head;
    return new_node;
}

// Insert after a given key
Node* insertAfter(Node* head, int key, int value) {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == key)
            break;
        curr = curr->next;
    }
    if (curr == nullptr) return head; // Key not found
    Node* newNode = new Node(value);
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}


// Print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);

    // Insert 20 at the beginning
    head = insertAtFirst(head, 20);
    printList(head); // Output: 20 10

    // Insert 30 after node with value 10
    head = insertAfter(head, 10, 30);
    printList(head); // Output: 20 10 30

    return 0;
}
