#ifndef SWEET_SANDWICH
#define SWEET_SANDWICH
#include <set>
#include "sandwich.h"
class SweetSandwich : public Sandwich
{
private:
    static std::set<int> _id_container;
    int _id = 0;
public:
    SweetSandwich () = default;
    SweetSandwich(int price, int id) : Sandwich(price, id)
    {
        _id = id;
        _id_container.insert(_id);
    }
    virtual ~SweetSandwich ()
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
std::set<int> SweetSandwich::_id_container;


#endif