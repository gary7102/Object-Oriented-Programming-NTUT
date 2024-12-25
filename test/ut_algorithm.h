#include <bits/stdc++.h>
#include "../src/sour.h"
#include "../src/tequila.h"
#include "../src/order.h"
#include "../src/algorithm.h"

TEST(ALGORITHM_TEST, test1){
    Tequila tequila1("Hello" , 50, 0.3);
    Tequila tequila2("Ha" , 50, 0.2);
    Tequila tequila3("Ya" , 50, 0.1);
    Alcohol *a;
    Alcohol *b;
    Alcohol *c;
    a = &tequila1;
    b = &tequila2;
    c = &tequila3;
    vector<Alcohol *> alcohol{a,b,c};
    sort_alcohol_by_content(alcohol);
    ASSERT_NEAR(alcohol[2]->get_alcohol_content(),0.3,0.01);
}

TEST(ALGORITHM_TEST, test2){
    Tequila tequila1("ZZZ" , 50, 0.3);
    Tequila tequila2("AAA" , 50, 0.2);
    Tequila tequila3("ABC" , 50, 0.1);
    Alcohol *a;
    Alcohol *b;
    Alcohol *c;
    a = &tequila1;
    b = &tequila2;
    c = &tequila3;

    vector<Alcohol *> alcohol{a,b,c};
    sort_alcohol_by_name(alcohol);
    ASSERT_EQ(alcohol[0]->get_name(),"AAA");
    ASSERT_EQ(alcohol[1]->get_name(),"ABC");
    ASSERT_EQ(alcohol[2]->get_name(),"ZZZ");
}

TEST(ALGORITHM_TEST, test3){
    Tequila tequila1("ZZZ" , 10, 0.1);
    Tequila tequila2("ABC" , 50, 0.2);
    Tequila tequila3("AAA" , 50, 0.2);
    Alcohol *a;
    Alcohol *b;
    Alcohol *c;
    a = &tequila1;
    b = &tequila2;
    c = &tequila3;
    vector<Alcohol *> alcohol{a,b,c};
    sort_alcohol_by_content(alcohol);
    ASSERT_EQ(alcohol[0]->get_name(),"ZZZ");
    ASSERT_EQ(alcohol[1]->get_name(),"AAA");
    ASSERT_EQ(alcohol[2]->get_name(),"ABC");
    ASSERT_EQ(get_greatest_content_of_alcohol(alcohol)->get_name(), "ABC");
    ASSERT_EQ(get_smallest_content_of_alcohol(alcohol)->get_name(), "ZZZ");
}

TEST(ORDER_TEST, test4)
{
    Order order;
    Tequila tequila1("ZZZ" , 10, 0.1);
    Tequila tequila2("ABC" , 50, 0.2);
    Tequila tequila3("AAA" , 50, 0.2);
    Alcohol *a;
    Alcohol *b;
    Alcohol *c;
    a = &tequila1;
    b = &tequila2;
    c = &tequila3;
    order.append_alcohol(a);
    order.append_alcohol(b);
    order.append_alcohol(c);
    ASSERT_EQ(order.get_alcohol_count(), 3);
    ASSERT_EQ(order.get_total_price(), 110);    
}

TEST(ALGORITHM_TEST,test5){
    Tequila tequila1("Hello" , 50, 0.3);
    Tequila tequila2("Ha" , 50, 0.2);
    Tequila tequila3("Ya" , 50, 0.1);
    Alcohol *a;
    Alcohol *b;
    Alcohol *c;
    a = &tequila1;
    b = &tequila2;
    c = &tequila3;
    vector<Alcohol *> alcohol{a,b,c};
    ASSERT_NEAR(get_smallest_content_of_alcohol(alcohol)->get_alcohol_content(),0.1,0.01);
}