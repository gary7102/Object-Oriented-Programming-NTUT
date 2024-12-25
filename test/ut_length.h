#include <gtest/gtest.h>
#include "../src/length.h"

TEST(LENGTH, TwoDim)
{
    double arr[2] = {3, 4};
    int dim = 2;
    double output = length(arr, dim);
    ASSERT_EQ(output, 5);
}

TEST(LENGTH, ThreeDIm)
{
    double arr[] = {3, 4, 5};
    int dim = 3;
    double output = length(arr, dim);
    ASSERT_NEAR(output, 7.07, 0.01);
}

TEST(LENGTH, FourDIm)
{
    double arr[] = {3, 4, 5, 6};
    int dim = 4;
    double output = length(arr, dim);
    ASSERT_NEAR(output, 9.27, 0.01);
}

TEST(LENGTH, TwoDimMathVector)
{
    double arr[2] = {3, 4};
    int dim = 2;
    MathVector m(dim, arr);
    double output = length(m);
    ASSERT_EQ(5, output);
}

TEST(LENGTH, ThreeDimMathVector)
{
    double arr[3] = {3, 4, 5};
    int dim = 3;
    MathVector m(dim, arr);
    double output = length(m);
    ASSERT_NEAR(output, 7.07, 0.01);
}

TEST(LENGTH, FourDimMathVector)
{
    double arr[4] = {3, 4, 5, 6};
    int dim = 4;
    MathVector m(dim, arr);
    double output = length(m);
    ASSERT_NEAR(output, 9.27, 0.01);
}