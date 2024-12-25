#ifndef SANDWICH_FACTORY
#define SANDWICH_FACTORY

#include <vector>
#include <stdexcept>
using namespace std;
template <typename T>
class SandwichFactory
{
private:
public:
    SandwichFactory() = default;
    ~SandwichFactory() = default;
    static T* create_sandwich(int price, int id)
    {
        return new T(price, id);
    }
    static std::vector<T*> create_sandwich_array(int price, int count, std::vector<int> id_list)
    {
        if(count < 0 || price < 0)
        {
            throw std::invalid_argument("invalid pric");
        }
        std::vector<T*> _vec;
        for(int i = 0; i<count; i++)
        {
            _vec.push_back(new T(price, id_list[i]));
        }
        return _vec;
    }
};

#endif







// #ifndef SANDWICH_FACTORY
// #define SANDWICH_FACTORY
// #include <vector>
// #include <stdexcept>
// using namespace std;

// template<typename T>
// class SandwichFactory
// {
// private:
// public:
//     SandwichFactory() = default;
//     ~SandwichFactory() = default;
//     static T* create_sandwich(int price, int id)
//     {
//         return (new T(price, id));
//     }
//     static vector<T*> create_sandwich_array(int price, int count, std::vector<int> id_list)
//     {
//         if(price < 0 || count < 0)
//         {
//             throw std::invalid_argument("error");
//         }
//         std::vector<T*> _vec;
//         for(i = 0 ;i < count; i++)
//         {
//             _vec.push_back(new T(price, id_list[i]));
//         }
//         return _vec;
//     }
// };

// #endif