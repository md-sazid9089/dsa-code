#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *next;
Node(int d):data(d),next(nullptr){}
};
void traverseList(Node* head){
while(head!= nullptr){
    cout<<head->data<<" ";
    head=head->next;
}
cout<<endl;
}
void recursetraverseList(Node* head){
if(head==nullptr){
    cout<<endl;
    return ;
}
cout<<head->data<<" ";
reversetraverseList(head->next);
}

int main(){
Node* head=new Node(10);
head->next=new Node(20);
head->next->next=new Node(30);
head->next->next->next=new Node(40);
traverseList(head);
recursetraverseList(head);
return 0;
}
