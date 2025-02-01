//1
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&a,int t,int start,int end1){
if(start<=end1){
    int mid=start+(end1-start)/2;
    if(a[mid]<t) return binarySearch(a,t,mid+1,end1);
    else if(a[mid]>t) return binarySearch(a,t,start,mid-1);
    else return mid;

}return-1;
}
int main(){
vector<int>a={1,2,3,4,5};
int target=5;
int result=binarySearch(a,target,0,a.size()-1);
if(result==-1){
    cout<<"not found"<<endl;
}
else{
cout<<"found at index: "<<result<<endl;
}
return 0;
}


//2
#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>&a,int n){
bool is_swap;
for(int i=0;i<n;i++){
    is_swap=false;
    for(int j=0;j<n-i-1;j++){
        if(a[j]>a[ j+1]){
                is_swap=true;
            swap(a[j],a[j+1]);
        }
    }
    if(!is_swap)return;
}


}
int main(){
vector<int>a={2,1,3,4,6,5};
int s=a.size();
bubble_sort(a,s);
for(int i=0;i<s;i++){
    cout<<a[i]<<endl;
}
return 0;
}

//3
#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>&v,int t,int high,int low){

while(low<=high){
    int mid=low+(high-low)/2;
    if(v[mid]<t)low=mid+1;
    else if(v[mid]>t) high=mid-1;
    else {
            cout<<"the index is "<<mid<<endl;
}
}
}
int main(){
vector<int>a={1,2,3,4,5};
int target=5;
int result=binarySearch(a,target,0,a.size()-1);
if(result==-1){
    cout<<"not found"<<endl;
}
else{
cout<<"found at index: "<<result<<endl;
}
return 0;
}
