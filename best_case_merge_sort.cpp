#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    int i = low, j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= high)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); ++k)
        arr[low + k] = temp[k];
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // Best-case optimization: only merge if needed
    if (arr[mid] > arr[mid + 1])
        merge(arr, low, mid, high);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:   ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

