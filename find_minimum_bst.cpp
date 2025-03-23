#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node* left;
Node* right;
};
struct Node* FindMin(struct Node* root){
while(root->left!=NULL){
    root=root->left;
}
return root;
};
struct Node* Insert(struct Node* root,int data){
if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else
		root->right = Insert(root->right,data);
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
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4);
	root = Insert(root,1); root = Insert(root,11);
    cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
struct Node* minNode=FindMin(root);
	cout<<"minimum is  "<<minNode->data<<" ";

}
