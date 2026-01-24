#include <string>

class log
{
private:
    void registerent(const std::string& text,const int& level);
public:
    log();
    void warn(const std::string& warns);
    void error(const std::string& error);
    void critical(const std ::string& critical);
    void info(const std::string& info);
    ~log();
};
