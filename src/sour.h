#ifndef SOUR_H
#define SOUR_H

#include<iostream>
#include "../src/alcohol.h"
using namespace std;

class Sour : public Alcohol
{
private:
    // string _name;
    // int _price;
    // double _content;
public:
    Sour(){};
    // void init(std::string name, int price, double content)
    // {
    //     (name.length() == 0)? throw string("error"): _name = name;
    //     (price < 0)? throw string("error"): _price = price;
    //     (content < 0 || content > 1)? throw string("error"): _content = content;
    // }
    Sour(string name, int price, double content) : Alcohol(name, price, content){}

    virtual ~Sour() = default;

    void dilute(void) override
    {
        _content *= 0.7;
    }
    Sour operator+(const Sour&other)
    {
        string name = this->_name;
        int price = this->_price + other._price;
        double content = (this->_content + other._content)/2;
        Sour tmp = Sour(name, price, content);
        return tmp;
    }
    bool operator==(const Sour &other)
    {
        // return (this != &other)? 0 : 1;
        if(this->_name != other._name)
        {
            return 0;
        }else if (this->_price != other._price)
        {
            return 0;
        }else if (this->_content != other._content)
        {
            return 0;
        }
        return 1;
    }
    Sour &operator=(const Sour &other)
    {
        if(this != &other)
        {
            init(other._name, other._price, other._content);
        }
        this->_name = other._name;
        this->_price = other._price;
        this->_content = other._content;
        return *this;
    }
};

#endif