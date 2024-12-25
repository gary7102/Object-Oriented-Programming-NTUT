#include <gtest/gtest.h>
#include "../src/drink.h"
#include <cmath>

/* Place some test here */
TEST(DrinkTest, Test)
{
    Drink drink_two;
    ASSERT_THROW(drink_two.getName(), string);
    ASSERT_THROW(drink_two.getSweetnessLevel(), string);
    ASSERT_THROW(drink_two.getPrice(), string);
}
TEST(DrinkTest, TestOne)
{
    Drink drink("Signature Black Tea with Milk", 0.3, 45);
    ASSERT_EQ(drink.getName(), "Signature Black Tea with Milk");  
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.3, 0.01);
    ASSERT_EQ(drink.getPrice(), 45);
}
TEST(DrinkTest, TestTwo)
{
    Drink drink("Signature Black Tea with Milk", 0.3, 45);
    drink.addTopping(Topping("Bubble", 0.15, 5));
    ASSERT_EQ(drink.getName(), "Signature Black Tea with Milk");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.45, 0.01);
    ASSERT_EQ(drink.getPrice(), 50);
}
TEST(DrinkTest, TestThree)
{
    Drink some_drink("Black Tea", 0.2, 15);  
    Drink drink;
    drink = some_drink;  
    ASSERT_EQ(drink.getName(), "Black Tea");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.2, 0.01);
    ASSERT_EQ(drink.getPrice(), 15);
}
TEST(DrinkTest, Important)
{
    Drink some_drink("Black Tea", 0.2, 15);
    some_drink.addTopping(Topping("Bubble", 0.15, 5));
    some_drink.addTopping(Topping("Pudding", 0.15, 10));
    Drink drink;
    drink = some_drink;
    ASSERT_EQ(drink.getName(), "Black Tea");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.5, 0.01);
    ASSERT_EQ(drink.getPrice(), 30);
    ASSERT_EQ(drink.getToppingCount(), 2);
}
TEST(DrinkTest, TestFour)
{
    Drink drink("Signature Black Tea with Milk", 0.3, 45);  
    drink.addTopping(Topping("Bubble", 0.15, 5));
    Topping topping = drink.getToppingByIndex(0);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_NEAR(topping.getSweetnessLevel(), 0.15, 0.01);
    ASSERT_EQ(topping.getPrice(), 5);
}
TEST(DrinkTest, TestFive)
{
    Drink drink("Signature Black Tea with Milk", 0.3, 45);
    drink.addTopping(Topping("Bubble", 0.15, 5));
    ASSERT_THROW(drink.getToppingByIndex(1), string);
    ASSERT_EQ(drink.getToppingCount(), 1);
}
TEST(DrinkTest, TestSix)
{
    ASSERT_THROW(Drink drink("Signature Black Tea with Milk", 1.2, 10), string);
}
TEST(DrinkTest, TestSeven)
{
    ASSERT_THROW(Drink drink("    ", 0.3, 10), string);
    // Drink drink("    ", 0.3, 10);
    // cout << drink.getName() << endl;
}
TEST(DrinkTest, TestEight)
{
    ASSERT_THROW(Drink drink("Signature Black Tea with Milk", 0.3, -1), string);
}
TEST(DrinkTest, TestNine)
{
    Drink drink("Milk Tea", 0.2, 30);  
    drink.addTopping(Topping("Bubble", 0.15, 5));
    drink.addTopping(Topping("Pudding", 0.15, 5));
    Topping topping = drink.getToppingByIndex(0);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_NEAR(topping.getSweetnessLevel(), 0.15, 0.01);
    ASSERT_EQ(topping.getPrice(), 5);
    Topping topping1 = drink.getToppingByIndex(1);
    ASSERT_EQ(topping1.getName(), "Pudding");
    ASSERT_NEAR(topping1.getSweetnessLevel(), 0.15, 0.01);
    ASSERT_EQ(topping1.getPrice(), 5);
    ASSERT_EQ(drink.getName(), "Milk Tea");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.5, 0.01);
    ASSERT_EQ(drink.getPrice(), 40);
    ASSERT_EQ(drink.getToppingCount(), 2);
}
TEST(DrinkTest, TestTen)
{
    Drink drink("Milk Tea", 0.8, 30);  
    drink.addTopping(Topping("Bubble", 0.3, 5));
    ASSERT_THROW(drink.getSweetnessLevel(), string);
}

TEST(DrinkTest, TestEleven)
{
    Drink drink("Milk Tea", 0.8, 30);  
    drink.addTopping(Topping("Bubble", 0.1, 5));
    Topping topping = drink.getToppingByIndex(0);
    ASSERT_EQ(drink.getName(), "Milk Tea");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.9, 0.01);
    ASSERT_EQ(drink.getPrice(), 35);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_NEAR(topping.getSweetnessLevel(), 0.1, 0.01);
    ASSERT_EQ(topping.getPrice(), 5);
    ASSERT_THROW(drink.getToppingByIndex(-1), string);
}