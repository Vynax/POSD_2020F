#include <gtest/gtest.h>
//#include "ut_app.h"
//#include "ut_folder.h"
//#include "ut_iterator.h"
//#include "ut_utility.h"
#include <string>
#include <iostream>

using namespace std;
//#include "ut_triangle.h"

int main(int argc, char *argv[])
{
    std::srand(std::time(0)); // use current time(?) as seed for random generator
    testing::InitGoogleTest(&argc, argv);
    string s = "123";
    s = s + "hello";

    cout << s << endl;
    return RUN_ALL_TESTS();
}

/*TEST(Shapes, First){
    ASSERT_TRUE(true);//之後改成true就會全綠
}*/