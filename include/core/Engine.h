#include "log/log.h"
#include "config.h"
#include "GUI/wall.h"
#include <optional>
class engine
{
private:
    logger L;
    std::optional<wall> creategui(API api);
public:
    engine(API type);
    void enginestart();
    ~engine();
};
