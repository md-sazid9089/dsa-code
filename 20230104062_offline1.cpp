#include<bits/stdc++.h>
using namespace std;

void Sorting(int n, vector<int>& v) {
    for(int i = 0; i < n - 1; i++) {
        int smallestindex = i;
        for(int j = i + 1; j < n; j++) {
            if(v[j] < v[smallestindex]) {
                smallestindex = j;
            }
        }
        int temp = v[i];
        v[i] = v[smallestindex];
        v[smallestindex] = temp;
    }
}

int Binary_search(vector<int>& arr, int start, int end1, int item) {
    while(start <= end1) {
        int mid = (start + end1) / 2;
        if(arr[mid] < item)
            return Binary_search(arr, mid + 1, end1, item);
        else if(arr[mid] > item)
            return Binary_search(arr, start, mid - 1, item);
        else
            return mid;
    }
    return start;
}

void printvector(vector<int>& a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
}

int main() {
    int n, target;
    cout << "Enter size of the vector:" << endl;
    cin >> n;
    vector<int> v(n);
    cout << "Enter the elements of the vector: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << "Enter a value to search:";
    cin >> target;

    Sorting(n, v);
    cout << "Sorted vector:";
    printvector(v, n);
    cout << endl;
    int result = Binary_search(v, 0, n - 1, target);
    if(result < n && v[result] == target)
        cout << "Value " << target << " found at " << result << endl;
    else {
        cout << "Value " << target << " can be inserted at index: " << result << " to maintain sorted order." << endl;
    }

    return 0;
}
