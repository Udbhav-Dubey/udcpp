#include <iostream>
#include <unordered_map>
using namespace std;
int main (){
    unordered_map<string,string> capital;
    capital={{"india","delhi"},
            {"usa","dc"},
            {"england","london"}};
    auto it=capital.begin(0);
    cout << it->first << " " << it->second;
return 0;
}
