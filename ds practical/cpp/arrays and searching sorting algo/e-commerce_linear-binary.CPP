#include <iostream>
#include <vector>
using namespace std;

// 1️⃣ Linear Search
int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i; // return index if found
    }
    return -1; // not found
}

// 2️⃣ Binary Search
int binarySearch(const vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // not found
}

int main() {
    vector<int> customer_ids = {101, 205, 309, 412, 523, 634, 745, 856, 967};
    int key;
    cout << "Enter customer ID to search: ";
    cin >> key;

    // Perform Linear Search
    int indexLinear = linearSearch(customer_ids, key);
    if (indexLinear != -1)
        cout << "[Linear Search] Customer ID " << key << " found at index " << indexLinear << endl;
    else
        cout << "[Linear Search] Customer ID " << key << " not found." << endl;

    // Perform Binary Search
    int indexBinary = binarySearch(customer_ids, key);
    if (indexBinary != -1)
        cout << "[Binary Search] Customer ID " << key << " found at index " << indexBinary << endl;
    else
        cout << "[Binary Search] Customer ID " << key << " not found." << endl;

    return 0;
}

