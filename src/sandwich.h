#ifndef SANDWICH
#define SANDWICH
#include <set>
#include <stdexcept>

class Sandwich
{
private:
    int _id = 0;
    int _price = 0;
    static std::set<int> _id_container;
public:
    Sandwich() = default;
    Sandwich(int price, int id)
    {
        (price < 0 || id < 0)? throw std::invalid_argument("invalid price") : _price = price; 
        (id < 0)? throw std::invalid_argument("invalid id") : _id = id;
        _id_container.insert(id);
    }
    virtual ~Sandwich()
    {
        _id_container.erase(_id);
    }
    int get_price()
    {
        return _price;
    }
    int get_id()
    {
        return _id;
    }
    static bool record_has_specific_id(int id)
    {
        return (_id_container.find(id) !=  _id_container.end());
    }
    static int get_size_of_record_container()
    {
        return _id_container.size();
    }
};
std::set<int> Sandwich::_id_container;

#endif







// #ifndef SANDWICH
// #define SANDWICH
// #include <set>
// #include <stdexcept>
// using namespace std;

// class Sandwich
// {
// private:
//     int _price = 0;
//     int _id = 0;
//     static std::set<int> _id_container;
// public:
//     Sandwich() = default;
//     Sandwich(int price, int id)
//     {
//         (price < 0)? throw std::invalid_argument("error") : _price = price;
//         (id < 0)? throw std::invalid_argument("error") : _id = id;
//         _id_container.insert(_id);
//     }
//     ~Sandwich()
//     {
//         _id_container.erase(_id);
//     }
//     int get_price()
//     {
//         return _price;
//     }
//     int get_id()
//     {
//         return _id;
//     }
//     static bool record_has_specific_id(int id)
//     {
//         return (_id_container(_id) != _id_container.end());
//     }
//     static int get_size_of_record_container()
//     {
//         return _id_container.size();
//     }
// };
// std::set<int> Sandwich::_id_container;

// #endif