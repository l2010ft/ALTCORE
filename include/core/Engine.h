#include "log/log.h"
#include "config.h"
#include "GUI/wall.h"
#include <optional>
#include <string>
#include <memory>
#include <string>
class engine
{
private:
    struct datP;
    std::unique_ptr<datP> data;
    logger L;
    std::unique_ptr<wall> creategui(API api,std::string& resp);
    void createwindow(int x = 800,int y = 600,std::string name = "ALTCORE",std::string& res);
public:
    engine(API type);
    void enginestart();
    ~engine();
};
