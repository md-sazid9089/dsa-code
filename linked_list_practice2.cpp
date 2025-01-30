#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *next;
Node(int data):data(data),next(nullptr){}
};

int main(){
    Node Node(10);
    cout<<"the output is:"<<Node.data;
    return 0;
}


