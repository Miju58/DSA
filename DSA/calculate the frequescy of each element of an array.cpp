#include <iostream>
using namespace std;

void calculateFrequency(int arr[], int size) {
    // Assuming elements in the array are non-negative and within a certain range
    const int MAX = 100; // Maximum value in the array
    int frequency[MAX] = {0}; // Array to store frequency of each element

    // Count the frequency of each element
    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;
    }

    // Print the frequency of each element
    cout << "Element | Frequency" << endl;
    cout << "--------|----------" << endl;
    for (int i = 0; i < MAX; i++) {
        if (frequency[i] != 0) {
            cout << "   " << i << "    |    " << frequency[i] << endl;
        }
    }
}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    calculateFrequency(arr, size);

    return 0;
}

