#include "Circle.h"

template<typename K_ID>
double Circle<K_ID>::area(void)
{
    return _radius*_radius*M_PI;
}
template<typename K_ID>
double Circle<K_ID>::perimeter(void)
{
    return _radius*2 *M_PI;
}
template<typename K_ID>
std::string Circle<K_ID>::getName(void)
{
    return "Circle::" + _name;
}

template<typename K_ID>
void Circle<K_ID>::expand(double input)
{
    _radius*=input;
}

template class Circle<int>;
template class Circle<double>;
// template class Circle<std::string>;