#ifndef COOKIE_H
#define COOKIE_H

using namespace std;

int check_x(bool** grid){
    /* Return the x-coordinate of the lastest of cookie. */
    int value = -1;
    for(int i=0; i<10; i++)
    {
        for(int j=9; j>=0; j--)
        {
            if(grid[i][j])
            {
                if (j>value)
                {
                    value = j;
                }
            }
        }
    }
    return value;
}

int check_y(bool** grid){
    /* Return the y-coordinate of the lastest of cookie. */
    int value = 9;
    for(int i=0; i<10; i++)
    {
        for(int j=9; j>=0; j--)
        {
            if(grid[j][i])
            {
                if (j<value)
                {
                    value = j;
                }
            }
        }
    }
    return value;
}

int print_grid(bool** grid){
    /* Print the grid you input. */
    /* Implement this function if necessary, it can help you to check your grid is correct or not. */
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j<10; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void placeTop(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    /* You can implement check_x(), check_y() above to get the x, y of the lastest cookie you place. */
    int x = check_x(grid);
    int y = check_y(grid);
    
    /* Check when you place cookie, it will out of bound or not. */
    if (y == 0)
    {
        throw string("out of range");
    }
    
    /* Place cookie from the top of current cookie. */
    grid[y-1][x] = 1;
}

void placeRight(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    int x = check_x(grid);
    int y = check_y(grid);

    /* Check when you place cookie, it will out of bound or not. */
    if (x == 9)
    {
        throw string("out of range");
    }
    /* Place cookie from the right of current cookie. */
    grid[y][x+1] =1;
}

int calcRow(bool** grid, int row){
    /* Calculate the count of cookie on the specific row */
    if(row>9)
    {
        return -1;
    }
    int value = 0;
    for(int i=0; i<10; i++)
    {
        value += grid[row][i];
    }
    return value;
}

int calcColumn(bool** grid, int column){
    /* Calculate the count of cookie on the specific column */
    if(column>9)
    {
        return -1;
    }
    int value = 0;
    for(int i=0; i<10; i++)
    {
        value += grid[i][column];
    }
    return value;
}

#endif