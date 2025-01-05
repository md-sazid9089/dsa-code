#include<bits/stdc++.h>
using namespace std;
int divide(vector<int> &a, int low, int high) {
    int index = low - 1;
    int pivot = a[high];

    for (int i = low; i < high; i++) {
        if (a[i] <= pivot) {
            index++;
            swap(a[i], a[index]);
        }
    }

    swap(a[high], a[index + 1]);
    return index + 1;
}

void quickSort(vector<int> &b, int low, int high) {
    if (low < high) {
        int p = divide(b, low, high);
        quickSort(b, low, p - 1);
        quickSort(b, p + 1, high);
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
