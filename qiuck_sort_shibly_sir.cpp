#include<bits/stdc++.h>
using namespace std;
int divide(vector<int> &a,int low,int high){
int pivot=a[low];
int i=low;
int j=high;
while(i<j){
      while(a[i]<=pivot){
        i++;
      }

      while(a[j]>pivot){
        --j;
      }
      if(i<j){
        swap(a[i],a[j]);
      }



      }
      swap(a[low],a[j]);
      return j;
}
void quickSort(vector<int> &b,int low,int upp){
if(low<upp){

   int p=divide(b,low,upp);
   quickSort(b,low,p-1);
   quickSort(b,p+1,upp);

   }


}


int main(){


int n;
cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
quickSort(a,0,n-1);
for(int i=0;i<n;i++){
    cout<<a[i]<<"  ";
}
return 0;
}
