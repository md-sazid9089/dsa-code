#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d) : data(d), prev(nullptr), next(nullptr) {}
};

Node* head = nullptr;
Node* tail = nullptr;
void reverse_link() {
    if (head == nullptr) return;
    Node* ptr1 = head;
    Node* ptr2 = ptr1->next;

    ptr1->next = nullptr;
    ptr1->prev = ptr2;

    while (ptr2 != nullptr) {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }

    head = ptr1;
}
void printList() {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Creating nodes
    head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    cout << "Original list: ";
    printList();

    reverse_link();

    cout << "Reversed list: ";
    printList();

    return 0;
}
