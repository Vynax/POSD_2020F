#include "../src/two_dimensional_coordinate.h"
#include "../src/triangle.h"
#include <vector>
#include <iostream>

TEST(Shapes, ExceptionTriangle)
{
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    try
    {

        Triangle triangle(triangleVector);
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("This is not a triangle!", e);
    }
    triangleVector.clear();
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    EXPECT_NO_THROW(triangleVector);
    triangleVector.clear();
}

TEST(Shapes, AreaTriangle)
{
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(4, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Triangle triangle(triangleVector);
    EXPECT_NEAR(8.0, triangle.area(), 0.001);
}

TEST(Shapes, PerimeterTriangle)
{
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(4, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Triangle triangle(triangleVector);
    EXPECT_NEAR(13.656, triangle.perimeter(), 0.001);
    //ASSERT_EQ(13.6569, triangle.perimeter());
}

TEST(Shapes, InfoTriangle)
{
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Triangle triangle(triangleVector);
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle.info());
}
