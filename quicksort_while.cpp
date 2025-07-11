#include <bits/stdc++.h>
using namespace std;
void quickSort(int arr[], int low, int high)
{
  while (low < high)
  {
    int pi = partition(arr, low, high);
    if (pi - low < high - pi)
    {
      quickSort(arr, low, pi - 1);
      low = pi + 1;
    }
    else
    {
      quickSort(arr, pi + 1, high);
      high = pi - 1;
    }
  }
}

