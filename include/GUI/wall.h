#include <string>
#include "log/log.h"
class wall
{
private:
    struct wallP;
public:
    wall(int Api,log log);
    void create(int X = 800,int Y = 600);

    ~wall();
};