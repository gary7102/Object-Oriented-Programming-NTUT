#include <bits/stdc++.h>
#include "../src/sour.h"
#include "../src/tequila.h"

TEST(TEQUILA_TEST, Test)
{
    Alcohol *a;
    Tequila c;
    ASSERT_THROW(Tequila("" , 50, 0.5), std::invalid_argument);
}

TEST(TEQUILA_TEST, TestTwo)
{
    Alcohol *a;
    Tequila c;
    c = Tequila("tequila" , 50, 0.5);
    a = &c;
    c.dilute();
    ASSERT_NEAR(a->get_alcohol_content(), 0.475, 0.01);
}

TEST(TEQUILA_TEST, TestThree)
{
    Alcohol *a;
    Tequila c;
    Tequila d;
    c = Tequila("tequila" , 50, 0.5);
    d = c;
    a = &d;
    d.dilute();
    ASSERT_NEAR(a->get_alcohol_content(), 0.475, 0.01);
}

TEST(TEQUILA_TEST, TestFour)
{
    Alcohol *a;
    Tequila c;
    Tequila d;
    c = Tequila("tequila" , 50, 0.5);
    d = c + c;
    a = &d;
    ASSERT_EQ(a->get_name(), "tequila");
    ASSERT_EQ(a->get_price(), 100);
    ASSERT_NEAR(a->get_alcohol_content(), 0.5, 0.01);
}

TEST(TEQUILA_TEST, TestFive)
{
    Alcohol *a;
    Tequila d;
    Tequila c = Tequila("tequila" , 50, 0.5);
    Tequila e = Tequila("no", 60, 0.7);
    d = c + e;
    a = &d;
    ASSERT_EQ(a->get_name(), "tequila");
    ASSERT_EQ(a->get_price(), 110);
    ASSERT_NEAR(a->get_alcohol_content(), 0.6, 0.01);
}

TEST(TEQUILA_TEST, TestSix)
{
    Tequila c = Tequila("tequila" , 50, 0.5);
    Tequila d = Tequila("no", 50, 0.5);
    Tequila e = Tequila("tequila", 60, 0.5);
    Tequila f = Tequila("tequila", 50, 0.6);
    ASSERT_FALSE(c == d);
    ASSERT_FALSE(c == e);
    ASSERT_FALSE(c == f);
}
TEST(TEQUILA_TEST, TestSeven)
{
    Tequila c = Tequila("tequila" , 50, 0.5);
    Tequila d = Tequila("tequila" , 50, 0.5);
    ASSERT_TRUE(c == d);
}