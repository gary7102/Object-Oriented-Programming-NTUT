#ifndef ORDER_H
#define ORDER_H

#include "alcohol.h"
#include <vector>
#include <algorithm>
// #include "algorithm.h"

class Order
{
private:
    std::vector <Alcohol *> _order;
public:
    Order(){};
    ~Order(){};
    void append_alcohol(Alcohol* alcohol)
    {
        _order.push_back(alcohol);
    }
    int get_alcohol_count()
    {
        return _order.size();
    }
    int get_total_price()
    {
        int total_price = 0;
        for(int i = 0; i<_order.size(); i++)
        {
            total_price += _order[i]->get_price();
        }
        return total_price;
    }
};

#endif