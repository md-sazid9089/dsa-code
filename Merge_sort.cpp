#include <bits/stdc++.h>
using namespace std;

void conquer(vector<int>& d, int l, int mid, int u) {
    vector<int> newarray;
    int idx1 = l;
    int idx2 = mid + 1;

    // Merge the two halves
    while (idx1 <= mid && idx2 <= u) {
        if (d[idx1] <= d[idx2]) {
            newarray.push_back(d[idx1++]);
        } else {
            newarray.push_back(d[idx2++]);
        }
    }
    // Copy remaining elements from left half
    while (idx1 <= mid) {
        newarray.push_back(d[idx1++]);
    }
    // Copy remaining elements from right half
    while (idx2 <= u) {
        newarray.push_back(d[idx2++]);
    }
    // Copy sorted elements back into the original array
    for (int i = 0; i < newarray.size(); i++) {
        d[l + i] = newarray[i];
    }
}

void divide(vector<int>& b, int start, int end1) {
    if (start >= end1) return; // Base case

    int mid = start + (end1 - start) / 2;
    divide(b, start, mid);        // Divide the left half
    divide(b, mid + 1, end1);     // Divide the right half
    conquer(b, start, mid, end1); // Conquer the two halves
}

void print(vector<int>& c) {
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    // Input elements into the vector
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Perform merge sort
    divide(v, 0, n - 1);

    // Print the sorted array
    print(v);

    return 0;
}
