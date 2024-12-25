#include "Triangle.h"

double Triangle::area(void)
{
    double a, b, c, s;
    a = (_x - _y).length();
    b = (_y - _z).length();
    c = (_z - _x).length();
    s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
double Triangle::perimeter(void)
{
    double tmp = (_x - _y).length();
    tmp += (_y - _z).length();
    tmp += (_z - _x).length();
    return tmp;
}
void Triangle::expand(double input)
{
    _y = _y / (1/input);
    _z = _z / (1/input);
}