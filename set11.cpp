#include <iostream>
#include <set>
using namespace std;
int main (){
    set<int>s1={1,23,532,543,23,323,4324,325,232323,322332,4,5,34};
    for (auto it=s1.begin();it!=s1.end();++it){
        cout << *it << " ";
    }
    cout << endl;
    cout << *s1.begin() << endl;
    cout << *--s1.end() << endl;
    cout << distance(s1.begin(),s1.end());
return 0;
}
