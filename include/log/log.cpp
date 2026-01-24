#include "log.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <filesystem>
class log
{
private:
    void registerent(const std::string& text,const int level){
        std::ofstream Logfile("logs/log.txt",std::ios::app);

        auto now = std::chrono::system_clock::now();

        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        std::string Noww = std::ctime(&now_c);
        Noww.pop_back();

        if (level == 0){
            Logfile << "[Warn]" << "[" + Noww + "]" << text + "\n";
        } else if (level == 1)
        {
            Logfile << "[Error]" << "[" + Noww + "]" << text + "\n";
        }else if (level == 2)
        {
            Logfile << "[Critical]" << "[" + Noww + "]" << text + "\n";
        }else if (level == 3)
        {
            Logfile << "[system]Logfile apagado :" << text; 
        }
        
        Logfile.close();
    }
public:
    log(){
        if (!std::filesystem::exists("logs")){
            std::filesystem::create_directory("logs");
        }
        if (!std::filesystem::exists("logs/log.txt"))
        {
            std::ofstream Logfile("logs/log.txt");
            Logfile.close();
        }
    }

    void warn(const std::string& warns){
        registerent(warns,0);
    }
    void error(const std::string& error){
        registerent(error,1);
    }
    void critical(const std::string& critical){
        registerent(critical,2);
    }
    ~log(){
        registerent("system",3);
    }
};
