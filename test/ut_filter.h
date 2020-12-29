#include "../src/filter.h"
#include "../src/shape_filter.h"
#include "../src/shape_setter.h"
#include <gtest/gtest.h>

class FilterTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        r34 = new Rectangle("0", 3, 4, "black");
        e43 = new Ellipse("1", 4, 3, "black");
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        t345 = new Triangle("2", triangleVector, "black");
    }

    void TearDown() override
    {
        delete r34;
        delete e43;
        delete t345;
        triangleVector.clear();
        //delete triangleVector;
    }
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    Shape *r34;
    Shape *e43;
    Shape *t345;
};

TEST_F(FilterTest, Filter)
{
    std::list<Shape *> data = {t345, r34, e43};
    // Filter *areaFilter = new ShapeFilter<bool (*)(Shape *)>([](Shape *shape) { return shape->area() < 30; });
    Filter *areaFilter = new ShapeFilter([](Shape *shape) { return shape->area() < 30; });
    Filter *perimeterFilter = new ShapeFilter([](Shape *shape) { return shape->perimeter() > 0; });
    Filter *colorFilter = new ShapeFilter([](Shape *shape) { return shape->color() == "black"; });

    areaFilter->setNext(perimeterFilter)->setNext(colorFilter);
    std::list<Shape *> results = areaFilter->push(data);
    std::list<Shape *>::const_iterator ptr = results.begin();
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", (*ptr)->info());
    ptr++;
    EXPECT_EQ("Rectangle (3.000, 4.000)", (*ptr)->info());
}

TEST_F(FilterTest, Filter_with_Setter)
{
    std::list<Shape *> data = {t345, r34, e43};
    // Filter *areaFilter = new ShapeFilter<bool (*)(Shape *)>([](Shape *shape) { return shape->area() < 30; });

    Filter *areaFilter = new ShapeFilter([](Shape *shape) { return shape->area() < 30; });
    Filter *perimeterFilter = new ShapeFilter([](Shape *shape) { return shape->perimeter() > 0; });
    Filter *colorSetter = new ShapeSetter([](Shape *shape) { shape->setColor("black"); });

    areaFilter->setNext(perimeterFilter)->setNext(colorSetter);
    std::list<Shape *> results = areaFilter->push(data);

    std::list<Shape *>::const_iterator ptr = results.begin();
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", (*ptr)->info());
    ptr++;
    EXPECT_EQ("Rectangle (3.000, 4.000)", (*ptr)->info());
}