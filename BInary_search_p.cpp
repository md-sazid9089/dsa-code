#include <bits/stdc++.h>
using namespace std;
/*
// Function to find the first occurrence
int firstOccurrence(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            result = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

// Function to find the last occurrence
int lastOccurrence(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            result = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int x = 2;

    int first = firstOccurrence(arr, x);
    int last = lastOccurrence(arr, x);

    cout << "First Occurrence: " << first << endl;
    cout << "Last Occurrence: " << last << endl;

    return 0;
}

//Find Lower Bound of X in a Sorted Array
#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size(); // High is n (not n-1)

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
            high = mid; // Move left
        else
            low = mid + 1; // Move right
    }
    return low; // Final position
}

int main() {
    vector<int> arr = {1,   2, 2, 3, 5, 7};
    int x = 2;

    cout << "Lower Bound of " << x << " is at index: " << lowerBound(arr, x) << endl;
    return 0;
}

//Upper Bound of x in a Sorted Array
#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size(); // High is n (not n-1)

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x)
            high = mid; // Move left
        else
            low = mid + 1; // Move right
    }
    return low; // Final position
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 5, 7};
    int x = 2;

    cout << "Upper Bound of " << x << " is at index: " << upperBound(arr, x) << endl;
    return 0;
}
//find the smallest missing element
#include <bits/stdc++.h>
using namespace std;

int findSmallestMissing(vector<int>& arr) {
    int low = 0, high = arr.size(); // High is n (not n-1)

    while (low < high) {
        int mid = low + (high - low) / 2;
`
        if (arr[mid] == mid)
            low = mid + 1; // Move right
        else
            high = mid; // Move left
    }
    return low; // Smallest missing number
}

int main() {
    vector<int> arr = {0, 1, 2, 6, 9, 11, 15};

    cout << "Smallest Missing Number: " << findSmallestMissing(arr) << endl;
    return 0;
}
*/

