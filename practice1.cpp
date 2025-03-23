#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n-1; i++) {
        int j=i+1;
        while(v[j]<v[j-1] && j>=1){
            swap(v[j],v[j-1]);
            j--;
        }
    }
}

int main() {
    vector<int> v = {5,4,3,1,2,6};
    insertionSort(v);

    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
