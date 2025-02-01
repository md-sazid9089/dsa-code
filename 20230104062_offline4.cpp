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

void insertAtFirst(int num) {
    Node* temp = new Node(num);
    temp->next = head;
    if (head != nullptr) {
        head->prev = temp;
    } else {
        tail = temp;
    }
    head = temp;
}

void insertAtLast(int num) {
    Node* temp = new Node(num);
    temp->prev = tail;
    if (tail != nullptr) {
        tail->next = temp;
    } else {
        head = temp;
    }
    tail = temp;
}

int listSize() {
    int size = 0;
    Node* curr = head;
    while (curr != nullptr) {
        size++;
        curr = curr->next;
    }
    return size;
}

void insertAtPosition(int t, int n) {
    if (n <= 1) {
        insertAtFirst(t);
        return;
    }

    int count1 = 1;
    Node* curr = head;
    while (curr != nullptr && count1 < n - 1) {
        curr = curr->next;
        count1++;
    }

    if (curr == nullptr) {
        insertAtLast(t);
        return;
    }

    Node* new_node = new Node(t);
    new_node->next = curr->next;
    new_node->prev = curr;

    if (curr->next != nullptr) {
        curr->next->prev = new_node;
    } else {
        tail = new_node; // If inserted at last position, update tail
    }

    curr->next = new_node;
}

int searching(int t) {
    Node* curr = head;
    int pos = 1;
    while (curr != nullptr) {
        if (curr->data == t) {
            return pos;
        }
        curr = curr->next;
        pos++;
    }
    return -1;
}

void insertByValue1(int t, int n) {
    int pos = searching(t);
    if (pos == -1) {
        cout << "Value not found!" << endl;
        return;
    }
    insertAtPosition(n, pos + 1);
}
void deleteFirst()
{
    if (head==nullptr && tail==nullptr)
        return;
    if (head==tail)
    {
        delete head;
        head= nullptr;
        tail = nullptr;
        return;
    }
    Node *curr =head;
    head=head->next;
     if (head!=nullptr)
    head->prev=nullptr;

    delete curr;
}

void deleteLast()
{
    if (head==nullptr)
        return;

    if (head==tail)
    {
        delete head;
        head =nullptr;
        tail =nullptr;
        return;
    }

    Node *curr = tail;
    tail = tail->prev;

    if (tail !=nullptr)
        tail->next =nullptr;

    delete curr;
}

void deleteByPos(int pos)
{
    if (head==nullptr)
        return;

    int size=listSize();

    if (pos<0 || pos>=size)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if (pos==0)
    {
        deleteFirst();
        return;
    }

    if (pos==size - 1)
    {
        deleteLast();
        return;
    }

    Node *curr =head;
    for (int i = 0; i < pos; i++)
        curr = curr->next;

    curr->prev->next=curr->next;

    if (curr->next!=nullptr)
        curr->next->prev = curr->prev;

    delete curr;
}

void deleteByValue(int tar)
{
    int pos = searching(tar);

    if (pos == -1){
        cout << "not found" << endl;
    return;
    }
    else
        deleteByPos(pos);
}
void printList() {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
void lastNode()
{   if (tail ==nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    cout << tail->data << endl;
}

void secondlastNode()
{
    if (tail ==nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    if (tail->prev == NULL)
    {
        cout << "List has only one element!" << endl;
        return;
    }
    cout << tail->prev->data << endl;
}

int main() {
    head = new Node(20);
    head->next = new Node(30);
    head->next->prev = head;
    head->next->next = new Node(40);
    head->next->next->prev = head->next;
    tail = head->next->next;

    printList();

    cout << "Insert at first position:" << endl;
    insertAtFirst(10);
    printList();
    cout<<endl;
    cout << "Insert at last position:" << endl;
    insertAtLast(50);
    printList();
    cout<<endl;
    cout << "List size: " << listSize() << endl;

    cout << "Inserting at position 2:" << endl;
    insertAtPosition(25, 2);
    printList();
    cout<<endl;
    int k = searching(40);
    if (k == -1) {
        cout << "Invalid search" << endl;
    } else {
        cout << "Position of 40: " << k << endl;
    }
    cout<<endl;
    cout << "Inserting 60 after 50:" << endl;
    insertByValue1(50, 60);
    printList();
    cout<<endl;
     cout << "Deleting the first node"<<endl;
    deleteFirst();
    printList();
    cout<<endl;

    cout << "Deleting the last node:"<<endl;
    deleteLast();
    printList();
    cout<<endl;

    cout << "Deleting by position: "<<endl;
    deleteByPos(1);
    printList();
    cout<<endl;

    cout << "Deleting by value"<<endl;
    deleteByValue(40);
    printList();
    cout<<endl;

    cout << "Checking last node:";
    lastNode();
    cout<<endl;

    cout << "Checking second last node:";
    secondlastNode();


    return 0;
}
