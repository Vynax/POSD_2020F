#include "../src/rectangle.h"

TEST(Shapes, ExceptionRectangle)
{
    try
    {
        Rectangle("0", 0, 1); //==> the argument should > 0 or the rectangle can't be build.
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("This is not a rectangle!", e);
    }

    EXPECT_NO_THROW(Rectangle("0", 1, 1));
}

TEST(Shapes, AreaRectangle)
{
    Rectangle rectangle("0", 50.1234, 4);
    //ASSERT_TRUE(12 == rectangle.area());
    EXPECT_NEAR(200.494, rectangle.area(), 0.001);
}

TEST(Shapes, PerimeterRectangle)
{
    Rectangle rectangle("0", 50.1234, 4);
    //ASSERT_TRUE(12 == rectangle.area());
    EXPECT_NEAR(108.247, rectangle.perimeter(), 0.001);
}

TEST(Shapes, InfoRectangle)
{
    Rectangle rectangle("0", 3.712, 4);

    EXPECT_EQ("Rectangle (3.712, 4.000)", rectangle.info());
}
