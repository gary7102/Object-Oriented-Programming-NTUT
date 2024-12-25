#include "../src/beef_sandwich.h"
#include "../src/sweet_sandwich.h"
#include "../src/sandwich_factory.h"

TEST(SANDWICH_TEST, test)
{
    BeefSandwich *bf1;
    BeefSandwich *bf2;
    SweetSandwich *sw1;
    SweetSandwich *sw2;
    ASSERT_THROW(SweetSandwich sw3 = SweetSandwich(-1, -1), std::invalid_argument);

    /* Pre create these sandwich */
    bf1 = new BeefSandwich(25, 0);
    sw1 = new SweetSandwich(15, 1);
    bf2 = new BeefSandwich(45, 2);
    sw2 = new SweetSandwich(25, 3);

    /* Check record in sandwich */
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(0)); // TRUE
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(1)); // TRUE
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(2)); // TRUE
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(3)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(0)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(1)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(2)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(3)); // TRUE

    /* Check record size in sandwich */
    ASSERT_EQ(BeefSandwich::get_size_of_record_container(), 2); // 2
    ASSERT_EQ(SweetSandwich::get_size_of_record_container(), 2); // 2
    ASSERT_EQ(Sandwich::get_size_of_record_container(), 4); // 4

    /* Delete some sandwich and check record */
    delete sw1;
    delete bf1;

    /* Check record in sandwich */
    ASSERT_FALSE(BeefSandwich::record_has_specific_id(0)); // FALSE
    ASSERT_FALSE(SweetSandwich::record_has_specific_id(1)); // FALSE
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(2)); // TRUE
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(3)); // TRUE
    ASSERT_FALSE(Sandwich::record_has_specific_id(0)); // FALSE
    ASSERT_FALSE(Sandwich::record_has_specific_id(1)); // FALSE
    ASSERT_TRUE(Sandwich::record_has_specific_id(2)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(3)); // TRUE

    /* Check record size in sandwich */
    ASSERT_EQ(BeefSandwich::get_size_of_record_container(), 1); // 1
    ASSERT_EQ(SweetSandwich::get_size_of_record_container(), 1); // 1
    ASSERT_EQ(Sandwich::get_size_of_record_container(),2 ); // 2
    
    delete bf2;
    delete sw2;
}

TEST(SANDWICH_TEST,test1)
{
    vector<SweetSandwich*> sweet_sandwich_set = SandwichFactory<SweetSandwich>::create_sandwich_array(15, 5, {33, 44, 55, 66, 99});
    // sweet_sandwich_set[0]: price 15, ID 33
    // sweet_sandwich_set[1]: price 15, ID 44
    // sweet_sandwich_set[2]: price 15, ID 55
    // sweet_sandwich_set[3]: price 15, ID 66
    // sweet_sandwich_set[4]: price 15, ID 99

    ASSERT_EQ(sweet_sandwich_set[0]-> get_id(),33);
    ASSERT_EQ(sweet_sandwich_set[1]-> get_id(),44);
    ASSERT_EQ(sweet_sandwich_set[2]-> get_id(),55);
    ASSERT_EQ(sweet_sandwich_set[3]-> get_id(),66);
    ASSERT_EQ(sweet_sandwich_set[4]-> get_id(),99);
    ASSERT_EQ(sweet_sandwich_set[0]-> get_price(),15);
    ASSERT_EQ(sweet_sandwich_set[1]-> get_price(),15);
    ASSERT_EQ(sweet_sandwich_set[2]-> get_price(),15);
    ASSERT_EQ(sweet_sandwich_set[3]-> get_price(),15);
    for (int i = 0; i < sweet_sandwich_set.size(); i++)
    {
        delete sweet_sandwich_set[i];
    }
    ASSERT_THROW(vector<SweetSandwich*> sweet_sandwich_set = SandwichFactory<SweetSandwich>::create_sandwich_array(15, -5, {33, 44, 55, 66, 99}), std::invalid_argument);
    ASSERT_THROW(vector<SweetSandwich*> sweet_sandwich_set = SandwichFactory<SweetSandwich>::create_sandwich_array(-15, 5, {33, 44, 55, 66, 99}), std::invalid_argument);

    
    // delete sweet_sandwich;

}

TEST(SANDWICH_TEST,test2)
{
    SweetSandwich* sweet_sandwich = SandwichFactory<SweetSandwich>::create_sandwich(15, 32767);
    // It should return a SweetSandwich pointer with price 15 and ID 32767.
    ASSERT_EQ(sweet_sandwich-> get_id(),32767);
    ASSERT_EQ(sweet_sandwich-> get_price(),15);
    ASSERT_EQ(sweet_sandwich->get_size_of_record_container(), 1);
    ASSERT_TRUE(sweet_sandwich->record_has_specific_id(32767));
    ASSERT_FALSE(sweet_sandwich->record_has_specific_id(1));
    delete sweet_sandwich;
}