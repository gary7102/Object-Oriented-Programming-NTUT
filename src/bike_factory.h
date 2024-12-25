#ifndef BIKE_FACTORY
#define BIKE_FACTORY

#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
class BikeFactory
{
private:
public:
    BikeFactory(/* args */);
    ~BikeFactory();
    static T* create_bike(int ID, int rent_price)
    {
        return (new T(ID, rent_price));
    }
    static std::vector<T*> create_bike_array(std::vector<int> IDs, std::vector<int> rent_prices)
    {
        std::vector<T*> _vec;
        for(int i = 0; i<IDs.size(); i++)
        {
            _vec.push_back(new T(IDs[i], rent_prices[i]));
        }
        return _vec;
    }
};


#endif