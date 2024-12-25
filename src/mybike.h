#ifndef MYBIKE
#define MYBIKE
#include "bike.h"
#include <string>

class MyBike : public Bike
{
private:
    int _id = 0;
    int _rent_price = 0;
    char buf[128] = {0};
public:
    MyBike(/* args */) = default;
    MyBike(int ID, int rent_price) : Bike(ID, rent_price)
    {
        (ID < 0)? throw std::invalid_argument("error") : _id = ID;
        (rent_price < 0)? throw std::invalid_argument("error") : _rent_price = rent_price;
    }
    virtual ~MyBike() = default;
    int get_id()
    {
        return _id;
    }
    int get_rental_price()
    {
        return _rent_price;
    }
    std::string to_string()
    {
        sprintf(buf, "%d-MyBike price=%d", _id, _rent_price);
        return buf;
    }
};

#endif