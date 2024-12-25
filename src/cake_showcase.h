#ifndef CAKE_SHOWCASE
#define CAKE_SHOWCASE
#include <string>
#include <vector>
#include <stdexcept>

template <typename T>
class CakeShowcase
{
private:
    char buf[128] = {0};
    int _length;
    std::vector<T*> _arr;
public:
    CakeShowcase()
    {
        _length = 0;
        _arr = NULL;
    }
    ~CakeShowcase() = default;
    CakeShowcase(int length, T** array)
    {
        _length = length;
        // _arr = new T[_length];
        for(int i = 0; i < _length; i++)
        {
            // _arr[i] = array[i];
            _arr.push_back(array[i]);
        }
    }
    int calc_total_price()
    {
        int total_price = 0;
        for(int i=0; i<_length; i++)
        {
            total_price += _arr[i]->get_price();
        }
        return total_price;
    }
    int calc_total_sweet()
    {
        int total_sweet = 0;
        for(int i=0; i<_length; i++)
        {
            total_sweet += _arr[i]->get_sweet();
        }
        return total_sweet;
    }
    std::string to_string()
    {
        std::string str_container;
        
        sprintf(buf, "| CakeName             | Price      | Sweet      |\n");
        printf("%s", buf);
        str_container += buf;
        sprintf(buf, "| -------------------- | ---------- | ---------- |\n");
        printf("%s", buf);
        str_container += buf;
        
        for(int i = 0; i<_length; i++)
        {
            str_container += _arr[i]->to_string();
            str_container += "\n";
        }
        sprintf(buf, "| -------------------- | ---------- | ---------- |");
        printf("%s", buf);
        str_container += buf;
        return str_container;
    }
    T* operator[](int index)
    {
        if(index >= _length || index < 0)
        {
            // throw std::string("out_of_range");
            throw std::out_of_range ("out_of_range");
        }
        return _arr[index];
    }
};

#endif


















/*
#ifndef CAKE_SHOWCASE
#define CAKE_SHOWCASE
#include <vector>
#include <stdexcept>

template<typename T>
class CakeShowcase
{
private:
    int _length = 0;
    std::vector<T*> _vec;
    char buf[128] = {0};
public:
    CakeShowcase() = default;
    CakeShowcase(int length, T** array)
    {
        _length = length;
        for(i=0; i<length; i++)
        {
            _vec.push_back(array[i]);
        }
    }
    ~CakeShowcase() = default;
    int calc_total_price()
    {
        int _total_price = 0;
        for(int i=0; i<_length; i++)
        {
            _total_price += _vec->get_price();
        }
    }
    int calc_total_sweet()
    {
        int _total_sweet = 0;
        for(int i=0; i<_length; i++)
        {
            _total_sweet += _vec->get_sweet();
        }
    }
    std::string to_string()
    {
        std::string str_container;
        sprintf(buf, "| CakeName             | Price      | Sweet      |");
        str_container += buf;
        sprintf(buf, "| -------------------- | ---------- | ---------- |");
        str_container += buf;
        for(int i = 0; i < _length; i++)
        {
            str_container += _vec[i].to_string();
            str_container += "\n";
        }
        sprintf(buf, "| -------------------- | ---------- | ---------- |");
        str_container += buf;
        return str_container;
    }
    T* operator[](int index)
    {
        if(index < 0 || index < _length)
        {
            throw std::out_of_range("error index");
        }
        return _vec[index];
    }
};

#endif
*/