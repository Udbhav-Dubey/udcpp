#include <bits/stdc++.h>
#define it vector<int>::iterator
using namespace std;

void mergeSortUtil(it left, it right) {
    if (right - left <= 1) return;

    it mid = left + (right - left) / 2;

    mergeSortUtil(left, mid);
    mergeSortUtil(mid, right);

    inplace_merge(left, mid, right);
}

void mergeSort(vector<int> &arr) {  // pass by reference here
    mergeSortUtil(arr.begin(), arr.end());

    for (int el : arr)
        cout << el << " ";
}

int main() {
    vector<int> arr = {5, 6, 3, 2, 1, 6, 7};
    mergeSort(arr);
    return 0;
}

