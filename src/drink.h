// #ifndef DRINK
// #define DRINK

// #include <string>
// #include <vector>
// #include "topping.h"

// using namespace std;

// class Drink{
// public:
//     Drink() = default;    //Default constructor
    
//     void init(std::string name, double sweetness_level, int price){
//         (name.length() <= 4)? throw string("name error"): _drink_name = name;
//         (sweetness_level < 0 || sweetness_level>1)? throw string ("undefined"): _drink_sweetness_level =sweetness_level;
//         (price < 0)? throw string("price error"): _drink_price = price;
//     }
//     /* The constructor of the Drink. */
// 	Drink(std::string name, double sweetness_level, int price){
//         init(name, sweetness_level, price);
//     }
//     /* The destructor of the Drink. */
//     ~Drink() = default;

//     /* Return the name of drink. */
//     std::string getName() const {
//         return (_drink_name.length() <= 4)? throw string("Empty name"): _drink_name;
//     }
//     /* Return the level of sweetness. */
//     double getSweetnessLevel() const{
//         return (_drink_sweetness_level<0 || _drink_sweetness_level>1)? throw string ("undefined"): _drink_sweetness_level;
//     }
//     /* Return the price of drink. */
// 	int getPrice() const {
//         return (_drink_price < 0)? throw string("Error"): _drink_price;
//     }
//     /* Add a topping to the drink. */
//     void addTopping(Topping topping){
//         _drink_price += topping.getPrice();
//         _drink_sweetness_level += topping.getSweetnessLevel();
//         _topping.push_back(topping.getName());
//         _topping_sweetnesslevel.push_back(topping.getSweetnessLevel());
//         _topping_price.push_back(topping.getPrice());
//     }
//     /* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
//     Topping getToppingByIndex(int index) const{
//         if(index >= _topping.size() || index<0){
//             throw string("out of range");
//         }
//         Topping t = Topping(_topping[index], _topping_sweetnesslevel[index], _topping_price[index]);
//         return t;
//     }
//     /* Get the count of topping in drink. */
//     int getToppingCount() const{
//         return _topping.size();
//     }
// 	/* Operator overloading */
// 	Drink &operator=(const Drink &other){
//         if(this != &other){
//             init(other._drink_name, other._drink_sweetness_level, other._drink_price);
//         }
//         _topping = other._topping;
//         _topping_sweetnesslevel = other._topping_sweetnesslevel;
//         _topping_price = other._topping_price;
//         return *this;
//     }
// private:
//     /* Put some attribute on here if necessary. */
//     string _drink_name = "";
//     double _drink_sweetness_level = -1;
//     int _drink_price = -1;
//     vector<string> _topping;
//     vector<double> _topping_sweetnesslevel;
//     vector<int> _topping_price;
// };

// #endif



////////////////////////////////////////////////////

#ifndef DRINK
#define DRINK

#include <vector>
#include <string>
#include "topping.h"
using namespace std;

class Drink
{
private:
    string _drink_name = "";
    double _drink_sweetness_level = -1;
    int _drink_price = -1;
    vector <string> _topping_name;
    vector <double> _topping_sweetness_level;
    vector <int> _topping_price;
public:
    Drink() = default;
    
    void init(std::string name, double sweetness_level, int price)
    {
    if((name.length() <= 4) || (name == "")){
        throw string("error");
    }else if (sweetness_level < 0 || sweetness_level >1){
        throw string("error");
    }else if (price < 0){
        throw string("error");
    }
    _drink_name = name;
    _drink_sweetness_level = sweetness_level;
    _drink_price = price;
    }

    Drink(std::string name, double sweetness_level, int price)
    {
        init(name, sweetness_level, price);
    }

    ~Drink() = default;

    std::string getName() const
    {
        return (_drink_name.length()<=4)? throw string("error"): _drink_name;
    }

    double getSweetnessLevel() const 
    {
        return (_drink_sweetness_level<0 || _drink_sweetness_level >1)? throw string("error"): _drink_sweetness_level;
    }

    int getPrice() const
    {
        return (_drink_price < 0)? throw string("error"): _drink_price;
    }

    Topping getToppingByIndex(int index) const
    {
        if(index >= _topping_name.size() || index < 0){
            throw string("error");
        }
        Topping t = Topping(_topping_name[index], _topping_sweetness_level[index], _topping_price[index]);
        return t;
    }

    void addTopping(Topping topping)
    {
        _drink_price += topping.getPrice();
        _drink_sweetness_level += topping.getSweetnessLevel();
        _topping_name.push_back(topping.getName());
        _topping_price.push_back(topping.getPrice());
        _topping_sweetness_level.push_back(topping.getSweetnessLevel());
    }

    int getToppingCount() const
    {
        return _topping_name.size();
    }

    Drink &operator=(const Drink &other)
    {
        if(this != &other)
        {
            init(other._drink_name, other._drink_sweetness_level, other._drink_price);
        }
        this->_topping_name = other._topping_name;
        this->_topping_sweetness_level = other._topping_sweetness_level;
        this->_topping_price = other._topping_price;
        return *this;
    }
};

#endif