#include <string>

class wall
{
private:
    struct wallP
    {
        int api;
        std::string name;
        int X;
        int Y;
        
    };
    
public:
    wall(int Api);
    void create(int X = 800,int Y = 600);

    ~wall();
};