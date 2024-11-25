#include<bits/stdc++.h>
using namespace std;

// Partition function to place the pivot element in its correct position
int partition(vector<int> &arr, int l, int h) {
    int pivot = arr[l]; // Use the first element as the pivot
    int i = l; 
    int j = h;

    while (i < j) {
        // Find the first element greater than or equal to the pivot from the left
        while (i <= h && arr[i] <= pivot) {
            i++;
        }
        // Find the first element less than or equal to the pivot from the right
        while (j >= l && arr[j] > pivot) {
            j--;
        }
        // Swap the elements if the indices have not crossed
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Place the pivot element in the correct position
    swap(arr[l], arr[j]);
    return j;
}

// QuickSort function
void quickSort(vector<int> &arr, int l, int h) {
    if (l < h) {
        //initially find the partition for the complete array
        int pi = partition(arr, l, h);
        // Recursively sort the subarrays
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

int main() {
    vector<int> arr = {1, 4, 2, 7, 4, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
}
