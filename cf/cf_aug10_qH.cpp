#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        vector<int> used(n, 0);
        vector<int> first_pair, second_pair;
        bool found1 = false;
        if (n==4){
            if (gcd(a[0],a[1])==1){
                if (gcd(a[2],a[3])==1){cout << "1 2 3 4"<<"\n";}
                else cout << 0 << endl;
            }
            else if (gcd(a[0],a[2])==1){
                if (gcd(a[1],a[3])==1){cout << "1 3 2 4" << "\n";}
                else cout << 0 << endl;
            }
            else if (gcd(a[0],a[3])==1){
                 if (gcd(a[1],a[2])==1){cout << "1 4 2 3" << '\n';}
                 else cout << 0 << endl;
            }
            continue;
        }
        for (int i = 0; i < n && !found1; i++) {
            for (int j = i + 1; j < n && !found1; j++) {
                if (gcd(a[i], a[j]) == 1) {
                    first_pair = {i + 1, j + 1}; 
                    used[i] = used[j] = 1;
                    found1 = true;
                }
            }
        }
        bool found2 = false;
        for (int i = 0; i < n && !found2; i++) {
            if (used[i]) continue;
            for (int j = i + 1; j < n && !found2; j++) {
                if (used[j]) continue;
                if (gcd(a[i], a[j]) == 1) {
                    second_pair = {i + 1, j + 1};
                    found2 = true;
                }
            }
        }
        if (found1 && found2) {
            cout << first_pair[0] << " " << first_pair[1] << " "
                 << second_pair[0] << " " << second_pair[1] << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}
