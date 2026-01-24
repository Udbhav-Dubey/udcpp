#include <bits/stdc++.h>
using namespace std;
int& getFirst(std::vector<int>& v)
{
    return v[0];
}
void printin(vector<int>&v){
    for (auto x : v){
        cout << x << " ";
    }
    cout << "\n";
}
int main()
{
    std::vector<int> v{1, 2, 3};
    int& r = getFirst(v);
    printin(v);
    v.push_back(4);   
    printin(v);
    r = 99;    
    printin(v);
    return 0;
}

