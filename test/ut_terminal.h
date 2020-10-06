#include <gtest/gtest.h>
#include "../src/terminal.h"
#include "../src/shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

TEST(Terminal, test)
{
    Terminal t123("Rectangle (3.7, 4.2) Ellipse (3, 4) Triangle ([0,-3], [-3,0], [0,-4]) area inc");
    t123.showResult();
}

TEST(Terminal, ignore)
{
    Terminal terminal("Rectangle (2, 2) Rectangle (1, 1) Ellipse$%^&(1, 1) area inc");
    ASSERT_EQ("1.000\n4.000", terminal.showResult());
}