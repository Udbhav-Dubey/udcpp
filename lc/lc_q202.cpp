#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ssum(int n) {
        int s = 0;
        while (n > 0) {
            int d = n % 10;
            s += d * d;
            n /= 10;
        }
        return s;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = ssum(n);
        }
        return n == 1;
    }
};

    cout << "please enter the number : ";
    int number;
    cin >> number;
    Solution sol;
    cout << "the answer is " << sol.isHappy(sol.isHappy(number));
return 0;
}
