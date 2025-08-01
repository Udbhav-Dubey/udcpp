#include <bits/stdc++.h>
using namespace std;

void printArray(int A[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void join(int arr[], int left[], int right[],
         int l, int m, int r)
{
    int i;
    for(i = 0; i <= m - l; i++)
        arr[i] = left[i];

    for(int j = 0; j < r - m; j++)
    {
        arr[i + j] = right[j];
    }
}

void split(int arr[], int left[], int right[],
          int l, int m, int r)
{
    for(int i = 0; i <= m - l; i++)
        left[i] = arr[i * 2];

    for(int i = 0; i < r - m; i++)
        right[i] = arr[i * 2 + 1];
}

void generateWorstCase(int arr[], int l,
                      int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        int left[m - l + 1];
        int right[r - m];

        split(arr, left, right, l, m, r);

        generateWorstCase(left, l, m);
        generateWorstCase(right, m + 1, r);

        join(arr, left, right, l, m, r);
    }
}

int main()
{
    
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,
                  10, 11, 12, 13, 14, 15, 16 };
                 
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Sorted array is \n";
    printArray(arr, n);

    generateWorstCase(arr, 0, n - 1);

    cout << "\nInput array that will result "
         << "in worst case of merge sort is \n";
         
    printArray(arr, n);

    return 0;
}

