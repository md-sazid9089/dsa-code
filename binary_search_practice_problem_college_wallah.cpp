/*given a sorted arry of n elements and a target 'x'.
find the first occurence of x in the array .if x doesnt exist return -1;
*/
#include<bits/stdc++.h>
using namespace std;
void BINARYsearch(vector<int>&b,int &n,int &target){
int beg=0;
int end1=n-1;
int idx=-1;

while(beg<=end1 ){
int mid=(beg+end1)/2;
    if(target<b[mid]) end1=mid-1;
    else if(target>b[mid]) beg=mid+1;
    else{
        if(mid>0 && b[mid]==b[mid-1]) end1=mid -1;
        else{
            idx=mid;
            break;
        }
    }
}
cout<<idx;

}
int main(){
vector<int>v={1,1,2,3,3,3,5,5,6,7};
int l=sizeof(v)/sizeof(v[0]);
int target1=3;
BINARYsearch(v,l,target1);


}
