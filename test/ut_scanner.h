#include "../src/scanner.h"

TEST(Scanner, Ellipse)
{
    Scanner scanner("Ellipse (4.000, 3.000)");

    EXPECT_EQ("Ellipse", scanner.nextToken());
    EXPECT_EQ("(", scanner.nextToken());
    EXPECT_EQ("4.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("3.000", scanner.nextToken());
    EXPECT_EQ(")", scanner.nextToken());

    try
    {
        scanner.nextToken();
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("next char doesn't exist.", e);
    }
}

TEST(Scanner, Rectangle)
{
    Scanner scanner("Rectangle (5.000, 3.000)");

    EXPECT_EQ("Rectangle", scanner.nextToken());
    EXPECT_EQ("(", scanner.nextToken());
    EXPECT_EQ("5.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("3.000", scanner.nextToken());
    EXPECT_EQ(")", scanner.nextToken());

    try
    {
        scanner.nextToken();
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("next char doesn't exist.", e);
    }
}

TEST(Scanner, Triangle)
{
    Scanner scanner("Triangle(0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");

    EXPECT_EQ("Triangle", scanner.nextToken());
    EXPECT_EQ("(", scanner.nextToken());
    EXPECT_EQ("0.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("0.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("0.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("-3.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("-4.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("0.000", scanner.nextToken());
    EXPECT_EQ(")", scanner.nextToken());

    try
    {
        scanner.nextToken();
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("next char doesn't exist.", e);
    }
}

TEST(Scanner, Compound_Shape)
{
    Scanner scanner("Compound Shape { Triangle([ 0.000, 0.000 ], [ 3.000, 0.000 ], [ 0.000, 4.000 ]), Rectangle(3.000, 4.000), Ellipse(4.000, 3.000) }");

    EXPECT_EQ("Compound", scanner.nextToken());
    EXPECT_EQ("Shape", scanner.nextToken());
    EXPECT_EQ("{", scanner.nextToken());

    EXPECT_EQ("Triangle", scanner.nextToken());
    EXPECT_EQ("(", scanner.nextToken());
    EXPECT_EQ("[", scanner.nextToken());
    EXPECT_EQ("0.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("0.000", scanner.nextToken());
    EXPECT_EQ("]", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("[", scanner.nextToken());
    EXPECT_EQ("3.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("0.000", scanner.nextToken());
    EXPECT_EQ("]", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("[", scanner.nextToken());
    EXPECT_EQ("0.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("4.000", scanner.nextToken());
    EXPECT_EQ("]", scanner.nextToken());
    EXPECT_EQ(")", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());

    EXPECT_EQ("Rectangle", scanner.nextToken());
    EXPECT_EQ("(", scanner.nextToken());
    EXPECT_EQ("3.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("4.000", scanner.nextToken());
    EXPECT_EQ(")", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());

    EXPECT_EQ("Ellipse", scanner.nextToken());
    EXPECT_EQ("(", scanner.nextToken());
    EXPECT_EQ("4.000", scanner.nextToken());
    EXPECT_EQ(",", scanner.nextToken());
    EXPECT_EQ("3.000", scanner.nextToken());
    EXPECT_EQ(")", scanner.nextToken());

    EXPECT_EQ("}", scanner.nextToken());
    try
    {
        scanner.nextToken();
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("next char doesn't exist.", e);
    }
}