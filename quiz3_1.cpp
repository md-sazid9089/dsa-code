#include <bits/stdc++.h>
using namespace std;

/*
Algorithm: Selection Sort (To Place Smallest Card in First Position)
Step 1: Iterate over the array from index 0 to 9
Step 2: Find the smallest number in the unsorted portion
Step 3: Swap it with the first element of the unsorted portion
Step 4: Continue until the entire array is sorted
*/

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // Assume the first element of unsorted part is the smallest

        // Step 2: Find the smallest element in the remaining unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Step 3: Swap smallest element with the first element of unsorted portion
        swap(arr[i], arr[minIndex]);

        // Print the array after each pass to show progress
        cout << "Pass " << i + 1 << ": ";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> cards = {17, 5, 23, 12, 8, 30, 2, 19, 14, 27}; // Example 10 cards

    cout << "Original Cards: ";
    for (int num : cards) {
        cout << num << " ";
    }
    cout << endl << endl;

    // Sort the cards
    selectionSort(cards);

    cout << "\nSorted Cards: ";
    for (int num : cards) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
=========================== PASS SIMULATIONS ===========================
Example Input:
cards = {17, 5, 23, 12, 8, 30, 2, 19, 14, 27}

Pass 1: (Find Smallest and Swap with First)
-------------------------------------------
Original: 17  5  23  12  8  30  2  19  14  27
Smallest: 2   → Swap with 17
After Swap: 2  5  23  12  8  30  17  19  14  27

Pass 2: (Find Smallest and Swap with Second)
-------------------------------------------
Smallest: 5  → Already in place
After Swap: 2  5  23  12  8  30  17  19  14  27

Pass 3: (Find Smallest and Swap with Third)
-------------------------------------------
Smallest: 8  → Swap with 23
After Swap: 2  5  8  12  23  30  17  19  14  27

Pass 4: (Find Smallest and Swap with Fourth)
-------------------------------------------
Smallest: 12 → Already in place
After Swap: 2  5  8  12  23  30  17  19  14  27

Pass 5: (Find Smallest and Swap with Fifth)
-------------------------------------------
Smallest: 14 → Swap with 23
After Swap: 2  5  8  12  14  30  17  19  23  27

Pass 6: (Find Smallest and Swap with Sixth)
-------------------------------------------
Smallest: 17 → Swap with 30
After Swap: 2  5  8  12  14  17  30  19  23  27

Pass 7: (Find Smallest and Swap with Seventh)
-------------------------------------------
Smallest: 19 → Swap with 30
After Swap: 2  5  8  12  14  17  19  30  23  27

Pass 8: (Find Smallest and Swap with Eighth)
-------------------------------------------
Smallest: 23 → Swap with 30
After Swap: 2  5  8  12  14  17  19  23  30  27

Pass 9: (Find Smallest and Swap with Ninth)
-------------------------------------------
Smallest: 27 → Swap with 30
After Swap: 2  5  8  12  14  17  19  23  27  30

Final Output:
Sorted Cards: 2 5 8 12 14 17 19 23 27 30
=======================================================================
*/
