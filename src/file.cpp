#include <iostream>
#include <fstream>
int main (){
    std::ofstream file("file.txt");
    file<<"entry\n";
    return 0;
}
