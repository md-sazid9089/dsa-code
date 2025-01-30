#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *next;
Node(int d):data(d),next(nullptr){}
};
bool searchkey(Node* head,int key){
while(head !=nullptr){
    if(head->data==key){
        return true;
    }
    head=head->next;
}
return false;

}

int main(){
Node* head=new Node(10);
head->next=new Node(20);
head->next->next=new Node(30);
head->next->next->next=new Node(40);
int key=20;
if(searchkey(head,key)){
    cout<<"Yes"<<endl;
}
else{
    cout<<"No"<<endl;
}
return 0;
}
