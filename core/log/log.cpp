#include <log.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
class log
{
private:
    void registerent(const std::string& text,const int level){
        std::ofstream Logfile("log.txt",std::ios::app);

        auto now = std::chrono::system_clock::now();

        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        std::string Noww = std::ctime(&now_c);
        Noww.pop_back();

        if (level == 0){
            Logfile << "[Warn]" << "[" + Noww + "]" << text;
        } else if (level == 1)
        {
            Logfile << "[Error]" << "[" + Noww + "]" << text;
        }else if (level == 2)
        {
            Logfile << "Critical" << "[" + Noww + "]" << text;
        }
        
        
    }
public:
    log(/* args */);
    ~log();
};
