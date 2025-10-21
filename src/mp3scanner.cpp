#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <algorithm>
namespace fs=std::filesystem;
class SongScanner(){
    private:
        std::vector<std::string>mp3Files;
    public :
        void scanDirectory(const std::string&directoryPath){
            mp3Files.clear(); 
        try{
            for (const auto&entry:fs::directory_iterator(directoryPath)){
                if (entry.is_regular_file()){
                    std::string filename=entry.path().filename().string();
                    if (filename.length()>4&&filename.substr(filename.length()-4)==".mp3"){
                        mp3.push_back(filename);
                    }
                }
            }
            std::sort(mp3Files.begin(),mp3Files.end());
        }
        catch(const fs::filesystem_error&e){
            std::cerr<<"[error] filesystem error : " << e.what() << "\n";
        }
}
    void printFiles() const {
        std::cout << "[info] Found " << mp3Files.size()<<"mp3 files:\n";
        for (size_t i=0;i<mp3.Files.size()<<++i){
            std::cout << i << ":::: "<< mp3Files[i] << "\n";
        }
    }
size_t count () const {return mp3Files.size();}
};

