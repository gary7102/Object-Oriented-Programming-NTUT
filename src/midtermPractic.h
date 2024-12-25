#ifndef MATH_VECTOR
#define MATH_VECTOR

#include <cmath>
#include <iostream>
#include <vector>

class MathVector
{
private:

    int _dim;
    double *_arr;   //uncertain size array
    std::vector<double> _arrV;
public:
    MathVector()
    {
        _dim = 0;
        _arr = NULL;
    }
    void init(int dim, double *arr)
    {
        _dim = dim;
        _arr = new double[_dim];
        for(int i=0; i<_dim; i++)
        {
            _arr[i] = arr[i];
        }
    }
    MathVector(int dim , double *arr)
    {
        init(dim, arr);
    }
    MathVector(const MathVector &input) : MathVector(input._dim, input._arr){}; //copy constructor, pass by reference
    MathVector(MathVector &&input)
    {
        this->_dim = input._dim;
        this->_arr = input._arr;

        input._dim = 0;
        input._arr = nullptr;
    }
    ~MathVector()
    {
        delete[] _arr;
    }
    MathVector &operator=(const MathVector &input)
    {
        if(this != input)
        {
            if(this != nullptr)
            {
                delete[] this->_arr;
            }
        }
        init(input._dim, input._arr);
        return *this;
    }
    // MathVector &operator=(const MathVector &&input); //move assignment
    MathVector operator+(const MathVector &input)
    {
        double *tmp = new double[input.getDim()];
        for(int i=0; i<input.getDim(); i++)
        {
            tmp[i] = this->_arr[i] + input._arr[i];
        }
        MathVector m = MathVector(input.getDim(), tmp);
        delete[] tmp;
        return m;
    }
    MathVector operator-(const MathVector &input)
    {
        double *tmp = new double[input.getDim()];
        for(int i=0; i<input.getDim(); i++)
        {
            tmp[i] = this->_arr[i] - input._arr[i];
        }
        MathVector m = MathVector(input.getDim(), tmp);
        delete[] tmp;
        return m;
    }
    MathVector operator/(const MathVector &input)
    {
        double *tmp = new double[input.getDim()];
        for(int i=0; i<input.getDim(); i++)
        {
            tmp[i] = this->_arr[i] / input._arr[i];
        }
        MathVector m = MathVector(input.getDim(), tmp);
        delete[] tmp;
        return m;
    }
    bool operator>(const MathVector &input)
    {
        return this->length() > input.length();
    }
    bool operator<(const MathVector &input)
    {
        return this->length() < input.length();
    }
    std::string toString()
    {
        std::string tmp = "Dim: ";
        tmp += std::to_string(_dim); 
        tmp += ", location is [";
        for(int i=0; i<_dim; i++)
        {
            tmp += std::to_string(_arr[i]);
            if(i != _dim-1)
                tmp += ", ";
        }
        tmp += "]";
        return tmp;
    }
    int getDim() const  //getter
    {
        return _dim;
    }
    double getIndex(int i) const
    {
        return _arr[i];
    }
    double length() const
    {
        double sum;
        for(int i=0; i<_dim; i++)
        {
            sum += pow(_arr[i], 2);
        }
        return sqrt(sum);
    }
    void multiply(double a)
    {
        for(int i=0; i<_dim; i++)
        {
            _arr[i] *= a;
        }
    }
};

#endif