#include <gtest/gtest.h>
#include "../src/HelloWorld.h"


TEST(Hello, PrintHelloWorld){
    string output = PrintHelloWorld();
    string compare = "Hello World! \n";
    ASSERT_EQ(output, compare);
}