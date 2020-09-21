#include "../src/two_dimensional_coordinate.h"
#include "../src/triangle.h"
#include <vector>
#include <iostream>

TEST(Shapes, Triangle)
{
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Triangle triangle(triangleVector);
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle.info());
}
