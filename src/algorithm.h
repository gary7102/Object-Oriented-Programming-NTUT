#include "alcohol.h"
#include <vector>
#include <algorithm>
using namespace std;

void sort_alcohol_by_content(vector<Alcohol*> &alcohol)
{
    if(alcohol.size() != 0)
    {
        std::sort(alcohol.begin(), alcohol.end(),
        [](Alcohol *a, Alcohol *b){  // Anonymous functin, a.k.a lambda function
            if(a->get_alcohol_content() == b->get_alcohol_content())
            {
                return a->get_name() < b->get_name();
            }else
            {
                return a->get_alcohol_content() < b->get_alcohol_content();
            }});
    }
}
void sort_alcohol_by_name(vector<Alcohol*> &alcohol)
{
    if(alcohol.size() != 0)
    {
        std::sort(alcohol.begin(), alcohol.end(),
        [](Alcohol *a, Alcohol *b){  // Anonymous functin, a.k.a lambda function
            return a->get_name() < b->get_name();
        });
    }
}
Alcohol* get_greatest_content_of_alcohol(vector<Alcohol*> alcohol)
{
    if(alcohol.size() != 0)
    {
        int size = alcohol.size();
        vector<Alcohol*> tmp;
        tmp = alcohol;
        sort_alcohol_by_content(tmp);
        return tmp[size-1];
    }
    return alcohol[-1];
}
Alcohol* get_smallest_content_of_alcohol(vector<Alcohol*> alcohol)
{
    if(alcohol.size() != 0)
    {
        vector<Alcohol*> tmp;
        tmp = alcohol;
        sort_alcohol_by_content(tmp);
        return tmp[0];
    }
    return alcohol[0];
}



    // std::sort(vec.begin(), vec.end(),
    // [](Alcohol *a, Alcohol *b){
    //     if(a->get_content() == b->get_content())
    //     {
    //         return a->get_name() < b->get_name();
    //     }else
    //     {
    //         return a->get_content() < b->get_content();
    //     }});