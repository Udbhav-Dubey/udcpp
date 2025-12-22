#include <iostream>
#include <fstream>
#include <string>
int main (){
    {
    std::ofstream file("data.txt");
    if(!file){
        std::cerr<<"Failed to oped data.txt\n";
        return 1;
    }
    file<<"Fresh start 1";
}
        std::ofstream file("data.txt",std::ios::app);
        if (!file){
            std::cerr<<"Failed to open data.txt in append mode\n";
            return 1;
        }
    int count=42;
    file<<"Count : " << count << "\n";
    std::streampos pos=file.tellp();
    file<<"Current cursor position " << pos << "\n";
    file.seekp(0,std::ios::end);
    file<<"After seek to end\n";
    file << "Flushing now ...\n";
    file.flush();
    
    return 0;
}
