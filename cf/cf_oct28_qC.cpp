#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool hasEven = false, hasOdd = false;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) hasEven = true;
            else hasOdd = true;
        }
        if (hasEven && hasOdd) {
            sort(a.begin(), a.end());
        }
        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
