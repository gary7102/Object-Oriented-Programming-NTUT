#ifndef TEQUILA_H
#define TEQUILA_H

#include<iostream>
#include "../src/alcohol.h"
using namespace std;

class Tequila : public Alcohol
{
private:

public:
    Tequila(){};
    
    Tequila(string name, int price, double content) : Alcohol(name, price, content){}

    virtual ~Tequila() = default;

    void dilute(void) override
    {
        _content *= 0.95;
    }
    Tequila operator+(const Tequila &other)
    {
        string name = this->_name;
        int price = this->_price + other._price;
        double content = (this->_content + other._content)/2;
        Tequila tmp = Tequila(name, price, content);
        return tmp;
    }
    bool operator==(const Tequila &other)
    {
        // return (this != &other)? 0 : 1;
        if(this->_name != other._name){
            return 0;
        }else if (this->_price != other._price){
            return 0;
        }else if (this->_content != other._content){
            return 0;
        }
        return 1;
    }
    Tequila &operator=(const Tequila &other)
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