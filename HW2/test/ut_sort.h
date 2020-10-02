#include <gtest/gtest.h>
#include "../src/sort.h"
#include "../src/shape.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

class ShapeSort : public ::testing::Test
{
protected:
    void SetUp() override
    {
        r34 = new Rectangle(3, 4);
        r22 = new Rectangle(2, 2);
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        t345 = new Triangle(triangleVector);
    }

    void TearDown() override
    {
        delete r34;
        delete r22;
        delete t345;
        triangleVector.clear();
        //delete triangleVector;
    }
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    Shape *r34;
    Shape *r22;
    Shape *t345;
};

//EXPECT_EQ(46.646, ellipse.area());
TEST_F(ShapeSort, SubtypePolymorphism)
{
    Shape *shapes[3] = {t345, r34, r22};
    EXPECT_EQ(6, shapes[0]->area());
    EXPECT_EQ(12, shapes[1]->area());
    EXPECT_EQ(4, shapes[2]->area());
}

TEST_F(ShapeSort, DescendingByArea)
{
    std::array<Shape *, 3> shapes = {t345, r34, r22};
    //printf("hefioah;fhe\n");
    quickSort(shapes.begin(), shapes.end(), areaDescendingCompare);
    EXPECT_EQ(12, shapes[0]->area());
    EXPECT_EQ(6, shapes[1]->area());
    EXPECT_EQ(4, shapes[2]->area());
}

TEST_F(ShapeSort, DescendingByPerimeter)
{
    std::array<Shape *, 3> shapes = {t345, r34, r22};
    //printf("hefioah;fhe\n");
    quickSort(shapes.begin(), shapes.end(), perimeterDescendingCompare);
    EXPECT_EQ(14, shapes[0]->perimeter());
    EXPECT_EQ(12, shapes[1]->perimeter());
    EXPECT_EQ(8, shapes[2]->perimeter());
}

TEST_F(ShapeSort, DescendingOnClass)
{
    std::array<Shape *, 3> shapes = {t345, r34, r22};
    quickSort(shapes.begin(), shapes.end(), DescendingCompare("area"));
    EXPECT_EQ(12, shapes[0]->area());
    EXPECT_EQ(6, shapes[1]->area());
    EXPECT_EQ(4, shapes[2]->area());
    quickSort(shapes.begin(), shapes.end(), DescendingCompare("perimeter"));
    EXPECT_EQ(14, shapes[0]->perimeter());
    EXPECT_EQ(12, shapes[1]->perimeter());
    EXPECT_EQ(8, shapes[2]->perimeter());
}

TEST_F(ShapeSort, AscendingByArea)
{
    std::array<Shape *, 3> shapes = {t345, r34, r22};
    //printf("hefioah;fhe\n");
    quickSort(shapes.begin(), shapes.end(), areaAscendingCompare);
    EXPECT_EQ(4, shapes[0]->area());
    EXPECT_EQ(6, shapes[1]->area());
    EXPECT_EQ(12, shapes[2]->area());
}

TEST_F(ShapeSort, AscendingByPerimeter)
{
    std::array<Shape *, 3> shapes = {t345, r34, r22};
    //printf("hefioah;fhe\n");
    quickSort(shapes.begin(), shapes.end(), perimeterAscendingCompare);
    EXPECT_EQ(8, shapes[0]->perimeter());
    EXPECT_EQ(12, shapes[1]->perimeter());
    EXPECT_EQ(14, shapes[2]->perimeter());
}

TEST_F(ShapeSort, AscendingOnClass)
{
    std::array<Shape *, 3> shapes = {t345, r34, r22};
    quickSort(shapes.begin(), shapes.end(), AscendingCompare("area"));
    EXPECT_EQ(4, shapes[0]->area());
    EXPECT_EQ(6, shapes[1]->area());
    EXPECT_EQ(12, shapes[2]->area());
    quickSort(shapes.begin(), shapes.end(), AscendingCompare("perimeter"));
    EXPECT_EQ(8, shapes[0]->perimeter());
    EXPECT_EQ(12, shapes[1]->perimeter());
    EXPECT_EQ(14, shapes[2]->perimeter());
}