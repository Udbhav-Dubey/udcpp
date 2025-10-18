#include <bits/stdc++.h>
using namespace std;
vector<int> quickSort(vector<int> &ar)
{
    if (ar.size() <= 1)
        return ar;
    int mid = ar.size() / 2;
    int pivot = ar[mid];
    vector<int> smaller;
    vector<int> greater;
    for (int ind = 0; ind < ar.size(); ind++
    {
        int val = ar[ind];
        if (ind != mid)
        {
            if (val < pivot)
                smaller.push_back(val);
            else if (val > pivot)
                greater.push_back(val);
            else
            {
                if (ind < mid)
                    smaller.push_back(val);
                else
                    greater.push_back(val);
            }
        }
    }
    vector<int> ans;
    vector<int> sa1 = quickSort(smaller);
    vector<int> sa2 = quickSort(greater);
    for (int val1 : sa1)
        ans.push_back(val1);
    ans.push_back(pivot);
    for (int val2 : sa2)
        ans.push_back(val2);
    return ans;
}
int main()
{
    vector<int> al = {10, 7, 8, 9, 1, 5};
    vector<int> sortedAr = quickSort(al);
    for (int x : sortedAr)
        cout << x << " ";
    return 0;
}
