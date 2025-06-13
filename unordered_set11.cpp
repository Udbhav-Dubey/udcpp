#include <bits/stdc++.h>
using namespace std;
int main (){
    unordered_set<int>s1;
    s1.emplace(5);
    s1.emplace(15);
    s1.emplace(30);
   // vector <int> vec={60,120};
    //s1.emplace(vec.begin(),vec.end());
    for (auto i : s1){
        cout << i << " ";
    }
    unordered_set<string>str;
    str.emplace("superman");
    str.emplace("save us");
    str.emplace("please");
    for (auto it : str){
        cout << it << " ";
    }
    return 0;
}
