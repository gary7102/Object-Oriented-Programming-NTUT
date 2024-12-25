#include <bits/stdc++.h>
#include "../src/sour.h"
#include "../src/tequila.h"

TEST(ALCOHOL_TEST, Test)
{
    Alcohol *a;
    Sour c;
    c = Sour("Hello" , 50, 0.5);
    a = &c;
    ASSERT_EQ(a->get_name() , "Hello");
    ASSERT_EQ(a->get_price(), 50);
    ASSERT_NEAR(a->get_alcohol_content(), 0.5, 0.01);
}
