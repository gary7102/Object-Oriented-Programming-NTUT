#ifndef ALCOHOL_H
#define ALCOHOL_H

#include<iostream>
using namespace std;

class Alcohol
{
protected:
    string _name;
    int _price;
    double _content;
public:
    Alcohol(): _name(""), _price(-1), _content(-1) {}; // Default constructor
    
    void init(std::string name, int price, double content)
    {
        (name.length() == 0)? throw std::invalid_argument("error"): _name = name;
        (price < 0)? throw std::invalid_argument("error"): _price = price;
        (content < 0 || content > 1)? throw std::invalid_argument("error"): _content = content;
    }
    Alcohol(std::string name, int price, double content)
    {
        init(name, price, content);
    }

    virtual ~Alcohol() = default;
    
    double get_alcohol_content()
    {
        return (_content < 0 || _content > 1)? throw string("error"): _content;
    }
    int get_price()
    {
        return (_price < 0)? throw string("error"): _price;
    }
    string get_name()
    {
        return (_name.length() == 0)? throw string("error"): _name;
    }
    
    virtual void dilute(void) = 0; // pure virtual function
};

#endif