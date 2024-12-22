#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {34, 4, 5, 6, 78}; // Input vector
    int n = a.size();                 // Size of the vector

    // Selection Sort Algorithm
    for (int i = 0; i < n - 1; i++) {
        int min1 = a[i]; // Assume the first element is the minimum
        int minidx = i;  // Store the index of the minimum element

        // Find the minimum element in the unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (a[j] < min1) {
                min1 = a[j];
                minidx = j;
            }
        }

        // Swap the minimum element with the first element of the unsorted portion
        int temp = a[i];
        a[i] = a[minidx];
        a[minidx] = temp;
    }

    // Print the sorted vector
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
