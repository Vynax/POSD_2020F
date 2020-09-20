#include "../src/rectangle.h"

TEST(Shapes, CreateRectangle){
    Rectangle rectangle(3.712, 4);
    //ASSERT_TRUE(12 == rectangle.area());
    ASSERT_EQ(14.848, rectangle.area());
    ASSERT_EQ("Rectangle (3.712, 4.000)", rectangle.info());
}