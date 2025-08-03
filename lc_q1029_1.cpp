#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int>& x, const vector<int>& y) {
    return (x[0] - x[1]) < (y[0] - y[1]);
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int totalPeople = costs.size();
        int n = totalPeople / 2;
        sort(costs.begin(), costs.end(), compare);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += costs[i][0]; 
        }
        for (int i = n; i < totalPeople; i++) {
            sum += costs[i][1];        }

        return sum;
    }
};
