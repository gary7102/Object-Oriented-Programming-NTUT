#include "../src/chocolate_cake.h"
#include "../src/geode_cake.h"
#include "../src/honey_cake.h"
#include "../src/cake_showcase.h"

TEST(CAKE_TEST, test)
{
    Cake *cake1;
    Cake *cake2;
    Cake *cake3;
    ChocolateCake *chocolate_cake1 = new ChocolateCake(45, 15);
    ChocolateCake *chocolate_cake2 = new ChocolateCake(45, 15);
    ChocolateCake *chocolate_cake3 = new ChocolateCake(45, 15);
    cake1 = chocolate_cake1;
    cake2 = chocolate_cake2;
    cake3 = chocolate_cake3;
    Cake *arr[3] = {cake1, cake2, cake3};
    CakeShowcase<Cake> cake_showcase(3, arr);
    // ASSERT_EQ();


    delete chocolate_cake1;
    delete chocolate_cake2;
    delete chocolate_cake3;
}

TEST(CAKE_TEST, test)
{
    Cake *c;
    ChocolateCake b(50,3);
    ChocolateCake *chocolate_cake = new ChocolateCake(50,3);
    ChocolateCake d(50,3);
    c = &b;
    ASSERT_EQ(c->get_sweet(),3);
    ASSERT_EQ(b.get_count(),3);
    delete chocolate_cake;
    ASSERT_EQ(b.get_count(),2);
    ASSERT_EQ(c->get_total(),2);
    b.to_string();
    ASSERT_EQ(b.to_string(),"| ChocolateCake        |         50 |         3 |");
}

TEST(CAKE_TEST, Test1)
{
    Cake *c;
    ChocolateCake *chocolate_cake1;
    ChocolateCake *chocolate_cake2;
    ChocolateCake *chocolate_cake3;
    HoneyCake *honey_cake1;
    HoneyCake *honey_cake2;
    HoneyCake *honey_cake3;
    chocolate_cake1 = new ChocolateCake(55, 40);
    chocolate_cake2 = new ChocolateCake(55, 40);
    chocolate_cake3 = new ChocolateCake(55, 40);
    honey_cake1 = new HoneyCake(55, 40);
    honey_cake2 = new HoneyCake(55, 40);
    honey_cake3 = new HoneyCake(55, 40);
    c = chocolate_cake1;
    chocolate_cake1->to_string();
    ASSERT_EQ(chocolate_cake1->get_count(), 3);
    ASSERT_EQ(c->get_price(), 55);
    ASSERT_EQ(c->get_sweet(), 40);
    ASSERT_EQ(c->get_total(), 6);
    delete chocolate_cake1;
    ASSERT_EQ(chocolate_cake2->get_count(), 2);
    ASSERT_EQ(c->get_total(), 5);
    delete chocolate_cake2;
    ASSERT_EQ(chocolate_cake3->get_count(), 1);
    ASSERT_EQ(c->get_total(), 4);
    delete chocolate_cake3;
    ASSERT_EQ(chocolate_cake3->get_count(), 0);
    ASSERT_EQ(c->get_total(), 3);
    delete honey_cake1;
    ASSERT_EQ(honey_cake2->get_count(), 2);
    ASSERT_EQ(c->get_total(), 2);
    delete honey_cake2;
    ASSERT_EQ(honey_cake3->get_count(), 1);
    ASSERT_EQ(c->get_total(), 1);
    delete honey_cake3;
    ASSERT_EQ(honey_cake3->get_count(), 0);
    ASSERT_EQ(c->get_total(), 0);
}

TEST(CAKE_TEST, Test2)
{
    Cake *c;
    HoneyCake *honey_cake;
    honey_cake = new HoneyCake(55, 40);
    c = honey_cake;
    honey_cake->to_string();
    ASSERT_EQ(honey_cake->get_count(), 1);
    ASSERT_EQ(c->get_price(), 55);
    ASSERT_EQ(c->get_sweet(), 40);
    ASSERT_EQ(c->get_total(), 1);
    delete honey_cake;
    ASSERT_EQ(honey_cake->get_count(), 0);
    ASSERT_EQ(c->get_total(), 0);
}

TEST(CAKE_TEST, Test3)
{
    Cake *c;
    GeodeCake *geode_cake;
    geode_cake = new GeodeCake(55, 40);
    c = geode_cake;
    geode_cake->to_string();
    ASSERT_EQ(geode_cake->get_count(), 1);
    ASSERT_EQ(c->get_price(), 55);
    ASSERT_EQ(c->get_sweet(), 40);
    ASSERT_EQ(c->get_total(), 1);
    delete geode_cake;
    ASSERT_EQ(geode_cake->get_count(), 0);
    ASSERT_EQ(c->get_total(), 0);
}


TEST(CAKE_TEST, Test4)
{
    Cake *c1;
    Cake *c2;
    Cake *c3;
    ChocolateCake *chocolate_cake1 = new ChocolateCake(45, 15);
    ChocolateCake *chocolate_cake2 = new ChocolateCake(45, 15);
    ChocolateCake *chocolate_cake3 = new ChocolateCake(45, 15);
    c1 = chocolate_cake1;
    c2 = chocolate_cake2;
    c3 = chocolate_cake3;
    Cake *arr[3] = {c1, c2, c3};
    CakeShowcase<Cake> cake_show_case(3, arr);
    ASSERT_EQ(cake_show_case.to_string(), "| CakeName             | Price      | Sweet      |\n| -------------------- | ---------- | ---------- |\n| ChocolateCake        |         45 |         15 |\n| ChocolateCake        |         45 |         15 |\n| ChocolateCake        |         45 |         15 |\n| -------------------- | ---------- | ---------- |");
    ASSERT_EQ(cake_show_case.calc_total_price(), 135);
    ASSERT_EQ(cake_show_case.calc_total_sweet(), 45);
    
    delete chocolate_cake1;
    delete chocolate_cake2;
    delete chocolate_cake3;
}