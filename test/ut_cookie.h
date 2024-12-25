#include <bits/stdc++.h>
#include "../src/cookie.h"

/* The function help you to create the empty grid. */
/* You can use this function or create by yourself. */
bool** create_grid(){
    bool** array = new bool*[10];
    for(int i = 0; i < 10; i++){
        array[i] = new bool[10];
        for(int j = 0; j < 10; j++){
            array[i][j] = false;
        }
    }
    array[9][0] = 1;
    return array;
}

/* The function help you to delete the grid. */
/* You should implement this by yourself. */
void delete_grid(bool** array){
    for(int i=0; i<10; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

/* Add some test in here. */

TEST(Cookie, Test1){
    bool** grid = create_grid();
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    ASSERT_EQ(calcRow(grid, 8), 2); // The first output
    ASSERT_EQ(calcColumn(grid, 1), 2); // The second output
    delete_grid(grid);
}

TEST(Cookie, Test2)
{
    bool** grid = create_grid();
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    ASSERT_EQ(calcRow(grid, 0), 0); // The first output
    ASSERT_EQ(calcRow(grid, 8), 1); // The second output
    ASSERT_EQ(calcColumn(grid, 0), 4); // The third output
    delete_grid(grid);
}


TEST(Cookie, Test3)
{
    bool** grid = create_grid();
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    ASSERT_THROW(placeTop(grid), string);
    delete_grid(grid);
}


TEST(Cookie, Test4)
{
    bool** grid = create_grid();
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    ASSERT_THROW(placeRight(grid), string);
    delete_grid(grid);
}

TEST(Cookie, Test5)
{
    bool** grid = create_grid();
    ASSERT_EQ(calcRow(grid, 48763), -1);
    delete_grid(grid);
}

TEST(Cookie, Test6)
{
    bool** grid = create_grid();
    ASSERT_EQ(calcRow(grid, 10), -1);
    delete_grid(grid);
}

TEST(Cookie, Test7)
{
    bool** grid = create_grid();
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    ASSERT_EQ(calcRow(grid, 5), 2);
    ASSERT_EQ(calcColumn(grid, 7), 1);
    delete_grid(grid);
}