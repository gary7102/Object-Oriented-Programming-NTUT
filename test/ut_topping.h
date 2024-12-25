#include <gtest/gtest.h>
#include "../src/drink.h"
#include <cmath>

TEST(ToppingTest, TestWithCopyConstructor){
    Topping topping("Bubble", 0.4, 5);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_EQ(topping.getSweetnessLevel(), 0.4);
    ASSERT_EQ(topping.getPrice(), 5);
}

TEST(ToppingTest, Test){
    Topping topping = Topping("Bubble", 0.4, 5);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_EQ(topping.getSweetnessLevel(), 0.4);
    ASSERT_EQ(topping.getPrice(), 5);
}

TEST(ToppingTest, TestWithCopyAssignment){
    Topping topping;
    topping = Topping("Bubble", 0.4, 5);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_EQ(topping.getSweetnessLevel(), 0.4);
    ASSERT_EQ(topping.getPrice(), 5);
}

TEST(ToppingTest, TestWithWrongValue){
    ASSERT_THROW(Topping("Bub", 0.4, 5), std::string);
    ASSERT_THROW(Topping("Bubble", -0.1, 5), std::string);
    ASSERT_THROW(Topping("Bubble", 0.4, -5), std::string);
}

TEST(ToppingTest, EmptyTopping)
{
    Topping topping;
    ASSERT_THROW(topping.getName(), string);
    ASSERT_THROW(topping.getSweetnessLevel(), string);
    ASSERT_THROW(topping.getPrice(), string);
}
TEST(ToppingTest, WrongToppingType)
{
    ASSERT_THROW(Topping topping("",2,3), string);
}

