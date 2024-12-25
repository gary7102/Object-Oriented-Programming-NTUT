#ifndef CAKE
#define CAKE
#include <string>

class Cake
{
private:
    int _price = 0;
    int _sweet = 0;
    static int _total;
public:
    Cake() = default;
    virtual ~Cake()
    {
        _total--;
    }
    Cake(int price, int sweet)
    {
        _price = price;
        _sweet = sweet;
        _total++;
    }
    int get_price()
    {
        return _price;
    }
    int get_sweet()
    {
        return _sweet;
    }
    static int get_total()
    {
        return _total;
    }
    virtual std::string to_string() = 0;
};

int Cake::_total;

#endif

/*
#ifndef CAKE
#define CAKE
#include <string>
using namespace std;

class Cake
{
private:
    int _price;
    int _sweet;
    static int _total;
public:
    Cake() = default;
    Cake(int price, int sweet)
    {
        (price < 0)? throw std::string("error price") : _price = price;
        (sweet < 0)? throw std::string("error price") : _sweet = sweet;
        _total++;
    }
    virtual ~Cake()
    {
        _total--;
    }
    int get_price()
    {
        return _price;
    }
    int get_sweet()
    {
        return _sweet;
    }
    static int get_total()
    {
        return _total;
    }
    virtual std::string to_string() = 0;
};
int Cake::_total;

#endif
*/