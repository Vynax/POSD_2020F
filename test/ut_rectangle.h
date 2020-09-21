#include "../src/rectangle.h"

TEST(Shapes, ExceptionRectangle)
{
    try
    {
        Rectangle(0, 1); //==> the argument should > 0 or the rectangle can't be build.
        FAIL();
    }
    catch (std::string e)
    {
        ASSERT_EQ("This is not a rectangle!", e);
    }

    ASSERT_NO_THROW(Rectangle(1, 1));
}

TEST(Shapes, AreaRectangle)
{
    Rectangle rectangle(50.1234, 4);
    //ASSERT_TRUE(12 == rectangle.area());
    ASSERT_EQ(200.494, rectangle.area());
}

TEST(Shapes, PerimeterRectangle)
{
    Rectangle rectangle(50.1234, 4);
    //ASSERT_TRUE(12 == rectangle.area());
    ASSERT_EQ(108.247, rectangle.perimeter());
}

TEST(Shapes, InfoRectangle)
{
    Rectangle rectangle(3.712, 4);

    ASSERT_EQ("Rectangle (3.712, 4.000)", rectangle.info());
}
