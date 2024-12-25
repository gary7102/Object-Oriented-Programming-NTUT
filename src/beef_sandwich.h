#ifndef BEEF_SANDWICH
#define BEEF_SANDWICH
#include <set>
#include "sandwich.h"

class BeefSandwich : public Sandwich
{
private:
    static std::set<int> _id_container;
    int _id = 0;
public:
    BeefSandwich() = default;
    BeefSandwich(int price, int id) : Sandwich(price, id)
    {
        _id = id;
        _id_container.insert(_id);
    }
    virtual ~BeefSandwich()
    {
        _id_container.erase(_id);
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
std::set<int> BeefSandwich::_id_container;

#endif