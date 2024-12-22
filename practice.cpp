#include<bits/stdc++.h>
using namespace std;
void Selection_sort(vector<int>&b){
int n=b.size();
for(int i=0;i<n-1;i++){
    int min1=1000;
    int minidx=-1;
    for(int j=i;j<n;j++){
        if(min1>b[j]){
            min1=b[j];
            minidx=j;
        }
    }
    int temp=b[i];
    b[i]=b[minidx];
    b[minidx]=temp;
}
}
void print_sort(vector<int>&c){
for(auto &d:c){
    cout<<d<<"  ";
}
}
int main(){
vector<int>a;
int n;
cin>>n;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a.push_back(x);
}
Selection_sort(a);
print_sort(a);

}
