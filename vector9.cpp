#include <iostream>
#include <vector>
int main (){
    std::   vector<int>v={1,4,5,6};
    std::    cout << v.at(2) << std:: endl;
    v.at(2)=9;
    std::cout << v.at(2);
    return 0;
}
