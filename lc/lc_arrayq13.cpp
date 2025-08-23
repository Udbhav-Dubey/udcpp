#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i + 1 < s.length() && values[s[i]] < values[s[i + 1]]) {
            num += values[s[i + 1]] - values[s[i]];
            i++; 
        } else {
            num += values[s[i]];
        }
    }
    return num;
}

int main() {
    string rom;
    cout << "Enter the Roman numeral: ";
    cin >> rom;  

    cout << rom << " = " << romanToInt(rom) << endl;
    return 0;
}

