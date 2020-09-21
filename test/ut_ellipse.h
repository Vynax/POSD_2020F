#include "../src/ellipse.h"

TEST(Shapes, ExceptionEllipse)
{
    try
    {
        Ellipse(0, 1); //==> the argument should > 0 or the rectangle can't be build.
        FAIL();
    }
    catch (std::string e)
    {
        ASSERT_EQ("This is not a ellipse!", e);
    }

    ASSERT_NO_THROW(Ellipse(1, 1));
}

TEST(Shapes, AreaEllipse)
{
    Ellipse ellipse(3.712, 4);
    ASSERT_EQ(46.646, ellipse.area());
}

TEST(Shapes, PerimeterEllipse)
{
    Ellipse ellipse(50.1234, 4);
    //ASSERT_EQ(209.626, ellipse.perimeter());
    ASSERT_NEAR(209.626, ellipse.perimeter(), 0.001);
}

TEST(Shapes, InfoEllipse)
{
    Ellipse ellipse(3.712, 4);

    ASSERT_EQ("Ellipse (3.712, 4.000)", ellipse.info());
}