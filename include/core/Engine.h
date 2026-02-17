#include "log/log.h"
#include "config.h"
#include "GUI/wall.h"
#include <optional>
#include <string>
#include <memory>
class engine
{
private:
    struct datP;
    std::unique_ptr<datP> data;
    logger L;
    std::optional<wall> creategui(API api,std::string& resp);
public:
    engine(API type);
    void enginestart();
    ~engine();
};
