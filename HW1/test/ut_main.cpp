
#include <gtest/gtest.h>
#include "ut_rectangle.h"
#include "ut_ellipse.h"
#include "ut_triangle.h"
#include <string>
#include <iostream>

using namespace std;
//#include "ut_triangle.h"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    string s = "123";
    s = s + "hello";

    cout << s << endl;
    return RUN_ALL_TESTS();
}

/*TEST(Shapes, First){
    ASSERT_TRUE(true);//之後改成true就會全綠
}*/