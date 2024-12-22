/*find ocurance in a sorted array*/
#include <bits/stdc++.h>
using namespace std;

void binarySearch(vector<int>& b, int n, int target) {
    int beg = 0;
    int end1 = n - 1;
    int idx = -1, idx2 = -1;

    while (beg <= end1) {
        int mid = beg + (end1 - beg) / 2;

        if (target < b[mid]) {
            end1 = mid - 1;
        } else if (target > b[mid]) {
            beg = mid + 1;
        } else {
            idx = mid;
            idx2 = mid;
            while (idx > 0 && b[idx - 1] == target) --idx;
            while (idx2 < n - 1 && b[idx2 + 1] == target) ++idx2;
            break;
        }
    }

    if (idx == -1) {
        cout << -1 << endl;
    } else {
        cout << "Range size: " << ((idx2 - idx) + 1) << endl;
    }
}

int main() {
    vector<int> v = {1, 3, 3, 3, 3, 3, 3, 3, 5, 7, 10, 12};
    int target1 = 3;
    binarySearch(v, v.size(), target1);
    return 0;
}
