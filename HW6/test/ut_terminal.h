#include <gtest/gtest.h>
#include "../src/terminal.h"
#include "../src/shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

TEST(Terminal, InvalidEllipse)
{
    try
    {
        Terminal t123("Rectangle (3.7, 4.2) Ellipse (3, 4) Triangle ([0,-3], [-3,0], [0,-4]) area inc");
        t123.showResult();
    }
    catch (std::string e)
    {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, ignore)
{
    Terminal terminal("Rectangle (2, 2) Rectangle (1, 1) Ellipse$%^&(1, 1) area inc");
    ASSERT_EQ("1.000\n4.000", terminal.showResult());
}

TEST(Terminal, AreaIncreasing)
{
    Terminal terminal("Rectangle (3.7, 4.2) Ellipse (4, 3) Triangle ([0,0], [-3,0], [0,-4]) area inc");
    ASSERT_EQ("6.000\n15.540\n37.699", terminal.showResult());
}
TEST(Terminal, AreaDecreasing)
{
    Terminal terminal("Rectangle (3.7, 4.2) Ellipse (4, 3) Triangle ([0,0], [-3,0], [0,-4]) area dec");
    ASSERT_EQ("37.699\n15.540\n6.000", terminal.showResult());
}

TEST(Terminal, AreaIncreasingWithOneShapeErrorArgumentIgnore)
{
    Terminal terminal("Rectangle (3.7, 4.2) Ellipse (4, 3) Triangle ([0,0], [-3,0], [0,-4]) Ellipse (four, 3) area inc");
    ASSERT_EQ("6.000\n15.540\n37.699", terminal.showResult());
}
