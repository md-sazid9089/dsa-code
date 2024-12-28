#include<bits/stdc++.h>
using namespace std;
int BInary_searach(vector<int>&arr,int start,int end1,int item){

while(start<=end1){
    int mid=(start+end1)/2;
    if(arr[mid]>item) return BInary_searach(arr,start,mid-1,item);
    else if(arr[mid]<item) return BInary_searach(arr,mid+1,end1,item);
    else return mid;
}return -1;

}
int main(){
vector<int>v;
for(iterator:: it=v.begin();it<v.end();it++){
    int x;
    cin>>x.push_back(*it);
}
int result=BInary_searach(v;0;v.size-1;8);
if(!result) cout<<"found"<<endl;
else cout<<"not found"<<endl;
return 0;



}
