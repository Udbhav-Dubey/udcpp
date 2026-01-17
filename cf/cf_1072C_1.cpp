#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k > n) {
            cout << -1 << '\n';
            continue;
        }

        bool found = false;
        for (int i = 0; i <= 31; i++) {
            long long pw = 1LL << i;
            long long low = n / pw;
            long long high = (n + pw - 1) / pw;

            if (k == low || k == high) {
                cout << i << '\n';
                found = true;
                break;
            }
        }

        if (!found)
            cout << -1 << '\n';
    }
    return 0;
}

