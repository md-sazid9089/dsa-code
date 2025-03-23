#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int item, int start, int end) {
    if (start <= end) {
        int mid = start + (end - start) / 2; // Avoid overflow
        if (item < arr[mid])
            return binarySearch(arr, item, start, mid - 1);
        else if (item > arr[mid])
            return binarySearch(arr, item, mid + 1, end);
        else
            return mid; // Element found
    }     return -1; // Element not found
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    int target = 7;
    int result = binarySearch(a, target, 0, a.size() - 1);

    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
