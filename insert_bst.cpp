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
void Inorder(struct Node* root) {
    if (root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int main(){
	Node* root = NULL;
	root = insertion(root,5); root = insertion(root,10);
	root = insertion(root,3); root = insertion(root,4);
	root = insertion(root,1); root = insertion(root,11);
    cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
}
