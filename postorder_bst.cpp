#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *left;
Node *right;
 Node(int val) {
        data = val;
        left = right = NULL;
    }
};
struct Node* insertion(struct Node* root,int data){
if(root==NULL){
     root=new Node(data);
   }
else if(data<= root->data){
    root->left=insertion(root->left,data);
}
else if(data> root->data){
    root->right=insertion(root->right,data);;
}
 return root;
};
void Postorder(struct Node* root) {
    if (root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
int main(){
	Node* root = NULL;
	root = insertion(root,5); root = insertion(root,10);
	root = insertion(root,3); root = insertion(root,4);
	root = insertion(root,1); root = insertion(root,11);
    cout<<"preorder: ";
	Postorder(root);
	cout<<"\n";
}

