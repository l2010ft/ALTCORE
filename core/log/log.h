#include <string>

class log
{
private:
    void registerent();
public:
    void warn(const std::string& warns);
    void error(const std::string& error);
    void critical(const std ::string& critical);
    ~log();
};
