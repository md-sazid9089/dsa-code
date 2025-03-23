// C++ program to merge two sorted linked lists
// using array
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to merge two sorted linked lists
Node *removeDuplicates(Node *head) {
    Node *curr = head;

    // Traverse the list
    while (curr != NULL && curr->next != NULL) {

        // Check if next value is same as current
        if (curr->data == curr->next->data) {
            Node *next_next = curr->next->next;
            curr->next = next_next;
        }
        else
            curr = curr->next;
    }
    return head;
}
void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    // First linked list: 5 -> 10 -> 15
    Node *head1 = new Node(5);
    head1->next = new Node(15);
    head1->next->next = new Node(15);

    // Second linked list: 2 -> 3 -> 20
    Node *head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    // Merging the two sorted linked lists
    Node *res = removeDuplicates(head1);

    printList(res);

    return 0;
}
