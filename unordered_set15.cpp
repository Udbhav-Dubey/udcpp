#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create two unordered_sets of the same type
    unordered_set<int> set1 = {1, 2, 3, 4};
    unordered_set<int> set2 = {100, 200, 300};

    cout << "Before swap:" << endl;
    cout << "set1: ";
    for (int val : set1) cout << val << " ";
    cout << "\nset2: ";
    for (int val : set2) cout << val << " ";
    cout << endl;

    // Swapping contents of set1 and set2
    set1.swap(set2);

    cout << "\nAfter swap:" << endl;
    cout << "set1: ";
    for (int val : set1) cout << val << " ";
    cout << "\nset2: ";
    for (int val : set2) cout << val << " ";
    cout << endl;

    return 0;
}

