#ifndef BIKE_RMS
#define BIKE_RMS
#include <vector>
#include <set>
#include <stdexcept>
#include "bike.h"
#include <algorithm>
class BikeRMS
{
private:
    // std::set<Bike*> _bikes;
    static std::vector<Bike*> _bikes;
    static int _total_rental_income;
public:
    BikeRMS(/* args */) = default;
    BikeRMS(std::vector<Bike*> bikes)
    {
        // for (int i = 0; i < bikes.size(); i++)
        // {
        //     _bikes.insert(bikes[i]);
        // }
        for(int i=0; i<bikes.size(); i++)
        {
            _bikes.push_back(bikes[i]);
        }
        // _bikes = bikes;
    }
    ~BikeRMS()
    {
        _bikes.clear();
    }
    int get_count_of_available_bike()
    {
        return _bikes.size();
    }
    Bike* rent_bike(int ID)
    {
        // if(_bikes.find(ID) !=  _bikes.end())
        // {
        //     throw std::invalid_arguments("error");
        // }
        int index=0;
        for(int i = 0; i<_bikes.size(); i++)
        {
            if(_bikes[i]->get_id() != ID && index == _bikes.size())
            {
                throw std::invalid_argument("error");
            }
            index++;
        }
        Bike* _rent_bike = _bikes[ID];
        _bikes.erase(_bikes.begin() + ID-1);
        return _rent_bike;
    }
    void return_bike(Bike* bike)
    {
        for(int i = 0; i<_bikes.size(); i++)
        {
            if(_bikes[i]->get_id() == bike->get_id() || bike->get_id() >_bikes.size())
            {
                throw std::invalid_argument("error");
            }
        }
        _bikes.insert(_bikes.begin()+bike->get_id()-2, bike);
    }
    void append_bike(Bike* bike)
    {
        for(int i = 0; i<_bikes.size(); i++)
        {
            if(_bikes[i]->get_id() == bike->get_id())
            {
                throw std::invalid_argument("error");
            }
        }
        _bikes.push_back(bike);
    }
    static int get_total_rental_income()
    {
        for(int i=0; i<_bikes.size(); i++)
        {
            _total_rental_income += _bikes[i]->get_rental_price();
        }
        return _total_rental_income;
    }
    static void reset_total_rental_income()
    {
        _total_rental_income = 0;
    }
};
int BikeRMS::_total_rental_income = 0;
std::vector<Bike*> BikeRMS::_bikes;

#endif