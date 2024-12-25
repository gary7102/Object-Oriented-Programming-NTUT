#ifndef BIKE
#define BIKE
#include <stdexcept>
class Bike
{
private:
    int _id = 0;
    int _rent_price = 0;
public:
    Bike(/* args */);
    Bike(int ID, int rent_price)
    {
        (ID < 0)? throw std::invalid_argument("error") : _id = ID;
        (rent_price < 0)? throw std::invalid_argument("error") : _rent_price = rent_price;

    }
    virtual ~Bike() = default;
    int get_id()
    {
        return _id;
    }
    int get_rental_price()
    {
        return _rent_price;
    }
    virtual std::string to_string() = 0;
};

#endif