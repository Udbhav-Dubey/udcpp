#include <iostream>
#include <fstream>
int main (){
    std::ofstream file("data.txt",std::ios::app);
    file<<"New line of text\n";
    return 0;
}
