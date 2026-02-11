#include "log/log.h"
#include "config.h"
#include "GUI/wall.h"
class engine
{
private:
    logger L;
    wall gui;
public:
    engine(API type);
    void enginestart();
    ~engine();
};
