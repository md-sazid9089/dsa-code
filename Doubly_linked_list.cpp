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

// Function to insert at the beginning
void insertAtBegin(int value) {
    Node* new_node = new Node(value);

    if (head == nullptr) {  // If list is empty
        head = new_node;
        tail = new_node;
        return;
    }

    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}
void insertAtPos(int value,int k){
Node* curr=head;
int count1=0;
while(count1<(k-1)){
    count1++;
    curr=curr->next;
}
Node* new_node=new Node(value);
new_node->next=curr->next;
curr->next=new_node;

new_node->prev=curr;
new_node->next->prev=new_node;
return;

}
void deleteHead( ){
if(head==nullptr){
    return;
}
Node* temp=head;
head=head->next;
if(head!=nullptr){
    head->prev=nullptr;
}
else tail=nullptr;
delete temp;

}
void deleteAtEnd(){
if(head==nullptr){
    return;
}
Node* temp=tail;
tail=tail->prev;
if(tail==nullptr){
    head=nullptr;
}else{
tail->next=nullptr;
}
delete temp;

}
void deleteAtposition(int k){
Node *temp=head;
int counter=1;
while(counter<k){
    temp=temp->next;
    counter++;
}
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
delete temp;

}
// Function to print the list
void printing() {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    insertAtBegin(20);
    insertAtBegin(10);
    insertAtBegin(5);

    printing();  // Output: 5 10 20
insertAtPos(15,1);
    printing();
    deleteHead();
    printing();
    deleteAtEnd();
    printing();
    deleteAtposition(3);
    printing();
    return 0;
}
