#ifndef PRODUCT
#define PRODUCT

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Product
{
private:
    string _name;
    int _price;
public:
    Product()
    {
        _name = "";
        _price = -1;
    }
    void init(std::string name, int price)
    {
        (name.length()<4)? throw string("error"): _name = name;
        (price < 0)? throw string("error"): _price = price;
    }
    Product(std::string name, int price)
    {
        init(name, price);
    }
    ~Product() = default;
    std::string getName() const
    {
        return (_name.length()<4)? throw string("error"): _name;
    }
    int getPrice() const
    {
        return (_price < 0)? throw string("error"): _price;

    }
    Product& operator=(const Product& other)
    {
        if(this != &other)
        {
            init(other._name, other._price);
        }
        
        return *this;
    }
    bool operator==(const Product& other)
    {
        if(this->_name == other._name)
        {
            return 1;
        }
        return 0;
    }
};



#endif