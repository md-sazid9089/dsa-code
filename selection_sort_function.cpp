


c#include <bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex])
                minIndex = j;
        }
        swap(v[i], v[minIndex]);
    }
}

int main() {
    vector<int> v = {5,4,3,1,2,6};
    SelectionSort(v);

    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
