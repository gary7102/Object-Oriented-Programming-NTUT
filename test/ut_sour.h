#include <bits/stdc++.h>
#include "../src/sour.h"
#include "../src/tequila.h"

TEST(SOUR_TEST, Test)
{
    Alcohol *a;
    Sour c;
    ASSERT_THROW(Sour("" , 50, 0.5), std::invalid_argument);
}

TEST(SOUR_TEST, TestTwo)
{
    Alcohol *a;
    Sour c;
    c = Sour("Lime" , 50, 0.5);
    a = &c;
    c.dilute();
    ASSERT_NEAR(a->get_alcohol_content(), 0.35, 0.01);
}

TEST(SOUR_TEST, TestThree)
{
    Alcohol *a;
    Sour c;
    Sour d;
    c = Sour("Lime" , 50, 0.5);
    d = c;
    a = &d;
    d.dilute();
    ASSERT_NEAR(a->get_alcohol_content(), 0.35, 0.01);
}

TEST(SOUR_TEST, TestFour)
{
    Alcohol *a;
    Sour c;
    Sour d;
    c = Sour("Lime" , 50, 0.5);
    d = c + c;
    a = &d;
    ASSERT_EQ(a->get_name(), "Lime");
    ASSERT_EQ(a->get_price(), 100);
    ASSERT_NEAR(a->get_alcohol_content(), 0.5, 0.01);
}

TEST(SOUR_TEST, TestFive)
{
    Alcohol *a;
    Sour d;
    Sour c = Sour("Lime" , 50, 0.5);
    Sour e = Sour("no", 60, 0.7);
    d = c + e;
    a = &d;
    ASSERT_EQ(a->get_name(), "Lime");
    ASSERT_EQ(a->get_price(), 110);
    ASSERT_NEAR(a->get_alcohol_content(), 0.6, 0.01);
}

TEST(SOUR_TEST, TestSix)
{
    Sour c = Sour("Lime" , 50, 0.5);
    Sour d = Sour("no", 50, 0.5);
    Sour e = Sour("Lime", 60, 0.5);
    Sour f = Sour("Lime", 50, 0.6);
    ASSERT_FALSE(c == d);
    ASSERT_FALSE(c == e);
    ASSERT_FALSE(c == f);
}
TEST(SOUR_TEST, TestSeven)
{
    Sour c = Sour("Lime" , 50, 0.5);
    Sour d = Sour("Lime" , 50, 0.5);
    ASSERT_TRUE(c == d);
}