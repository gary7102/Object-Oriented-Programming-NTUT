#ifndef SHOOPING_CART
#define SHOOPING_CART

#include <cmath>
#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

class ShoppingCart
{
private:
    vector <std::string> _item_name;
    vector <int> _item_price;
public:
    ShoppingCart() = default;
    void init(int item_list_size, Product* item_list)
    {
        for(int i=0; i<item_list_size; i++){
            _item_name.push_back(item_list[i].getName());
            _item_price.push_back(item_list[i].getPrice());
        }
    }
    ShoppingCart(int item_list_size, Product* item_list)
    {
        for(int i=1; i<item_list_size; i++){
            if(item_list[i].getName() == item_list[i-1].getName()){
                throw string("error");
            }
        }
        init(item_list_size, item_list);
    }
    ~ShoppingCart() = default;
    int getItemCount() const
    {
        // cout << _item_name << endl;
        return _item_name.size();
    }
    Product getItemByIndex(int index) const
    {
        if(index<0 || index>= _item_name.size()){
            throw string("error");
        }
        Product p = Product(_item_name[index], _item_price[index]);
        return p;
    }
    void setItemByIndex(int index, Product product)
    {
        if(index<0 || index>= _item_name.size()){
            throw string("error");
        }
        for(int i=0; i<_item_name.size(); i++)
        {
            if(product.getName() == _item_name[i]){
                throw string("error");
            }
        }
        _item_name[index] = product.getName();  
        _item_price[index] = product.getPrice();
    }
    void appendItem(Product product)
    {
        for(int i=0; i<_item_name.size(); i++)
        {
            if(product.getName() == _item_name[i]){
                    throw string("error");
            }
        }
        _item_name.push_back(product.getName());
        _item_price.push_back(product.getPrice());
    }
    int getTotalCost() const
    {
        int sum = 0;
        for(int i=0; i<_item_name.size(); i++)
        {
            sum += _item_price[i];
        }
        return sum;
    }
    ShoppingCart& operator-(const ShoppingCart& other)
    {
        vector <string> name;
        vector <int> price;
        int count = 0;
        for(int i=0; i<this->getItemCount(); i++)
        {
            count = 0;
            for (int j=0; j<other.getItemCount(); j++)
            {
                if(other._item_name[j] != this->_item_name[i])
                {
                    if((count+1) == other.getItemCount()){
                        name.push_back(this->_item_name[i]);
                        price.push_back(this->_item_price[i]);
                    }
                    count +=1;
                }
            }
        }
        this->_item_name = name;
        this->_item_price = price;
        return *this;
    }
    ShoppingCart& operator+(const ShoppingCart& other)
    {
        vector <string> name;
        vector <int> price;
        for(int i=0; i<other.getItemCount(); i++)
        {
            name.push_back(this->_item_name[i]);
            price.push_back(this->_item_price[i]);
        }
        for(int i=0; i<this->getItemCount(); i++)
        {
            for (int j=0; j<other.getItemCount(); j++)
            {
                if(other._item_name[j] != this->_item_name[i])
                {
                    name.push_back(other._item_name[i]);
                    price.push_back(other._item_price[i]);
                }
            }
        }
        this->_item_name = name;
        this->_item_price = price;
        return *this;
    }
    ShoppingCart& operator=(const ShoppingCart& other)
    {
        if(this != &other)
        {
            Product* products = new Product[other.getItemCount()];
            for(int i=0; i<other.getItemCount(); i++)
            {
                products[i] = Product(other._item_name[i], other._item_price[i]);
            }
            init(other.getItemCount(), products);
        }
        return *this;
    }
};




#endif