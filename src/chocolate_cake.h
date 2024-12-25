#ifndef CHOCOLATE_CAKE
#define CHOCOLATE_CAKE

#include <stdio.h>
#include "cake.h"

class ChocolateCake : public Cake
{
private:
    char buf[128] = {0};
    static int _total;
public:
    ChocolateCake() = default;
    virtual ~ChocolateCake()
    {
        _total--;
    }
    ChocolateCake(int price, int sweet) : Cake(price, sweet)
    {
        _total++;
    }
    std::string to_string() override
    {
        // sprintf(buf, "| ChocolateCake        |         %d |         %d |\n", _price, _sweet);
        sprintf(buf, "| ChocolateCake        |         %d |         %d |", this->get_price(), this->get_sweet());
        printf("%s", buf);
        return buf;
    }
    static int get_count()
    {
        return _total;
    }
};
int ChocolateCake::_total = 0;

#endif


/*
#ifndef CHOCOLATE_CAKE
#define CHOCOLATE_CAKE
#include <stdio.h>
#include "cake.h"

class ChocolateCake : public Cake
{
private:
    char buf[128] = {0};
    static int _total;
public:
    ChocolateCake() = default;
    ChocolateCake(int price, int sweet) : Cake(price, sweet)
    {
        _total++;
    }
    virtual ~ChocolateCake()
    {
        _total--;
    }
    virtual std::string to_string()
    {
        sprintf(buf, "| ChocolateCake        |         %d |         %d |", this->get_price(), this->get_sweet());
        return buf;
    }
    static int get_count()
    {
        return _total;
    }
};
int ChocolateCake::_total;

#endif
*/