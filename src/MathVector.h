#ifndef MATH_VECTOR
#define MATH_VECTOR

#include <cmath>
#include <iostream>
#include <vector>

class MathVector
{
friend std::ostream &operater<<(std::ostream &output, const MathVector &m);
private:
    int _dim;
    double *_arr;   //uncertain size array
    std::vector<double> _arrV;
public:
    MathVector();    //Default constructor
    void init(int dim, double *arr);
    // MathVector(int dim , double *arr); //inline function call  //Constructor
    // MathVector(int dim , int *arr);
    MathVector(int dim , void *arr);
    MathVector(const MathVector &input) : MathVector(input._dim, input._arr){}; //copy constructor, pass by reference
    MathVector(MathVector &&input) noexcept;                  //move constructor
    ~MathVector();                                   //destructor
    MathVector &operator=(const MathVector &input);  //copy assignment, assignment operator overloading
    MathVector &operator=(MathVector &&input); //move assignment
    MathVector operator+(const MathVector &input) const;   //operator overloading
    MathVector operator-(const MathVector &input) const;   //operator overloading
    MathVector operator/(const MathVector &input) const;   //operator overloading
    MathVector operator/(int input) const;   //operator overloading
    bool operator>(const MathVector &input);
    bool operator<(const MathVector &input);
    friend std::istream &operater>>(std::istream &input, const MathVector &m)
    {
        input >> m._dim;
        double tmp* = new double tmp[m._dim];
        for(int i = 0;i < m._dim; i++)
        {
            input >> tmp[i];
        }
        // TBD
        return input;
    }
    std::string toString();
    int getDim() const; //getter
    double getIndex(int i) const;
    double length() const;
    void multiply(double a);
};

std::ostream &operater<<(std::ostream &output, const MathVector &m)
{
    std::stringstream ss;
    ss << m._dim << std::endl;
    for(int i = 0;i < m._dim; i++)
    {
        ss >> tmp[i] >> ", ";
    }
    output << ss;
    return output; 
}

#endif