#ifndef HONEY_CAKE
#define HONEY_CAKE
#include "cake.h"
#include <string>

class HoneyCake : public Cake
{
private:
    char buf[128] = {0};
    static int _total;
    std::string _str;
public:
    HoneyCake() = default;
    virtual ~HoneyCake() override
    {
        _total --;
    }
    HoneyCake(int price, int sweet) : Cake(price, sweet)
    {
        _total ++;
    }
    std::string to_string() override
    {
        sprintf(buf, "| HoneyCake            |         %d |         %d |", this->get_price(), this->get_sweet());
        printf("%s", buf);
        return buf;
    }
    static int get_count()
    {
        return _total;
    }
};
int HoneyCake::_total = 0;

#endif