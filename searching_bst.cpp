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
     return root;
   }
else if(data<= root->data){
    root->left=insertion(root->left,data);
}
else if(data> root->data){
    root->right=insertion(root->right,data);
}
 return root;
};
void Preorder(struct Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
struct Node* Search(Node *root,int val){
while(root!=NULL && root->data!=val){
    root=val<root->data? root->left:root->right;
}
return root;
};
int main(){
	Node* root = NULL;
	root = insertion(root,5); root = insertion(root,10);
	root = insertion(root,3); root = insertion(root,4);
	root = insertion(root,1); root = insertion(root,11);
    cout<<"preorder: ";
	Preorder(root);
	cout<<"\n";
	int val=4;
	if(Search!=NULL) cout<<"value  "<<val<<"   found";
	else  cout<<"value  "<<val<<"not found";
return 0;
}


