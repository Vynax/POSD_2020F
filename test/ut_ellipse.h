#include "../src/ellipse.h"

TEST(Shapesjjjjj, ExceptionEllipse)
{
    try
    {
        Ellipse("0", 0, 1); //==> the argument should > 0 or the Ellipse can't be build.
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("This is not an ellipse!", e);
    }

    EXPECT_NO_THROW(Ellipse("0", 1, 1));
}

TEST(Shapes, AreaEllipse)
{
    Ellipse ellipse("0", 4, 3.712);
    EXPECT_EQ(46.646, ellipse.area());
}

TEST(Shapes, PerimeterEllipse)
{
    Ellipse ellipse("0", 50.1234, 4);
    //ASSERT_EQ(209.626, ellipse.perimeter());
    //cout << "hi" << endl;
    EXPECT_NEAR(209.626, ellipse.perimeter(), 0.001);
}

TEST(Shapes, InfoEllipse)
{
    Ellipse ellipse("0", 4, 3.712);

    EXPECT_EQ("Ellipse (4.000, 3.712)", ellipse.info());
}