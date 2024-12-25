#ifndef ELECTRIC_BIKE
#define ELECTRIC_BIKE
#include "bike.h"
#include <string>

class ElectricBike : public Bike
{
private:
    int _id = 0;
    int _rent_price = 0;
    double _power = 0;
    char buf[128] = {0};
public:
    ElectricBike(/* args */) = default;
    ElectricBike(int ID, int rent_price, double power = 0) : Bike(ID, rent_price)
    {
        (ID < 0)? throw std::invalid_argument("error") : _id = ID;
        (rent_price < 0)? throw std::invalid_argument("error") : _rent_price = rent_price;
        (power < 0 || power > 1)? throw std::invalid_argument("error") : _power = power;
    }
    virtual ~ElectricBike() = default;
    int get_id()
    {
        return _id;
    }
    int get_rental_price()
    {
        return _rent_price;
    }
    double get_power()
    {
        return _power;
    }
    void set_power(double power)
    {
        (power < 0 || power > 1)? throw std::invalid_argument("error") : _power = power;
    }
    std::string to_string()
    {
        sprintf(buf, "%d-ElectricBike price=%d power=%.2f", _id, _rent_price, _power);
        return buf;
    }
};

#endif