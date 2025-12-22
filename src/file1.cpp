#include <iostream>
#include <fstream>
int main (){
    std::ofstream file("file1.txt",std::ios::app);
    file<<"Hello\n";
    file<<"world\n";
return 0;
}
