#include "log/log.h"
#include "config.h"
#include "GUI/wall.h"
#include <optional>
#include <string>
class engine
{
private:
    logger L;
    std::optional<wall> creategui(API api,std::string& resp);
public:
    engine(API type);
    void enginestart();
    ~engine();
};
