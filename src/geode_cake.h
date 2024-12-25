#ifndef GEODE_CAKE
#define GEODE_CAKE
#include "cake.h"
#include <string>

class GeodeCake : public Cake
{
private:
    char buf[128] = {0};
    static int _total;
    std::string _str;
public:
    GeodeCake() = default;
    virtual ~GeodeCake() override
    {
        _total --;
    }
    GeodeCake(int price, int sweet): Cake(price, sweet)
    {
        _total ++;
    }
    std::string to_string() override
    {
        sprintf(buf, "| GeodeCake            |         %d |         %d |", this->get_price(), this->get_sweet());
        printf("%s", buf);
        return buf;
    }
    static int get_count()
    {
        return _total;
    }
};
int GeodeCake::_total = 0;

#endif