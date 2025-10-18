#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void findInDeque(const deque<int>& q, int target) {
    auto itr = std::find(q.begin(), q.end(), target);
    if (itr != q.end()) {
        cout << "Found " << target << endl;
    } else {
        cout << "Not Found" << endl;
    }
}

int main() {
    deque<int> q = {1, 2, 3, 4, 5};
    
    findInDeque(q, 2);  
    findInDeque(q, 10);

    return 0;
}

