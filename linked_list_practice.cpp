#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int data) : data(data), next(nullptr) {}
};
//(1) insertBegin() -> function to insert a node at the begin
void insertBegin(Node **head, int value) {
    Node *newNode = new Node(value);
    newNode->next = *head;
    *head = newNode;
}
// (2) insertEnd() -> function to insert a node at the end
void insertEnd(Node *&head, int value) {
    Node *newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}
//(3) insertAtPosition() -> function to insert a node at a given position
void insertAtPosition(Node **head, int value, int position) {
    if (position == 1) {
        insertBegin(head, value);
        return;
    }
    Node *newNode = new Node(value);
    Node *current = *head;
    int count = 1;
    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}
//(4) deleteBegin() -> function to remove a node from the begin
void deleteBegin(Node **head) {
    if (*head == nullptr) return;
    Node *temp = *head;
    *head = (*head)->next;
    delete temp;
}
// (5) deleteEng() -> function to remove a node from the end
void deleteEnd(Node *&head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node *current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}
//(6) deleteFromPosition() -> function to remove a node from the given positionvoid deleteFromPosition(Node **head, int position) {
    if (*head == nullptr) return;
    if (position == 1) {
        deleteBegin(head);
        return;
    }
    Node *current = *head;
    int count = 1;
    while (current != nullptr && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == nullptr || current->next == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
}
//(7) printList() -> function to print the linked list
void printList(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
//(8) searchList() -> function to search a value in the linked list
void searchList(Node *head, int value) {
    Node *current = head;
    int index = 0;
    while (current != nullptr) {
        if (current->data == value) {
            cout << "Value found at index " << index << endl;
            return;
        }
        current = current->next;
        index++;
    }
    cout << "Value not found\n";
}
//(9) last_node() -> function to print the value of the last node
void last_node(Node *head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    while (head->next != nullptr) {
        head = head->next;
    }
    cout << head->data << endl;
}
//(10) second_last_node() -> function to print the value of the previous node of last node
void second_last_node(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        cout << "No second last node\n";
        return;
    }
    while (head->next->next != nullptr) {
        head = head->next;
    }
    cout << head->data << endl;
}
//(11) list_size() -> function to print the size of the linked list
void list_size(Node *head) {
    int size = 0;
    while (head != nullptr) {
        size++;
        head = head->next;
    }
    cout << size << endl;
}
//(12) printReverse() -> function to print the linked list in reverse order
void printReverse(Node *head) {
    if (head == nullptr) return;
    printReverse(head->next);
    cout << head->data << " ";
}
int main() {
    Node *head = nullptr;
    insertBegin(&head,100);
    printList(head);

    insertEnd(head, 200);
    printList(head);

    insertAtPosition(&head, 15, 2);
    printList(head);

    deleteBegin(&head);
    printList(head);

    deleteEnd(head);
    printList(head);

    insertEnd(head, 25);
    insertEnd(head, 30);
    printList(head);

    deleteFromPosition(&head, 2);
    printList(head);

    searchList(head, 25);
    searchList(head, 40);

    cout << "Last node value:";
    last_node(head);

    cout << "Second last node value:";
    second_last_node(head);

    cout << "List size:";
    list_size(head);

    cout << "List in reverse:";
    printReverse(head);
    cout << endl;

    return 0;
}
