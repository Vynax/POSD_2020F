#include "../src/shape_builder.h"

TEST(ShapeBuilderTest, build_Triangle)
{
    ShapeBuilder sb;
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    std::deque<Shape *> results = sb.getResult();

    EXPECT_EQ(1, results.size());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[0]->info());
}

TEST(ShapeBuilderTest, build_Ellipse)
{
    ShapeBuilder sb;
    sb.buildEllipse(4.000, 3.000);
    std::deque<Shape *> results = sb.getResult();

    EXPECT_EQ(1, results.size());
    EXPECT_EQ("Ellipse (4.000, 3.000)", results[0]->info());
}

TEST(ShapeBuilderTest, build_Rectangle)
{
    ShapeBuilder sb;
    sb.buildRectangle(5.000, 3.000);
    std::deque<Shape *> results = sb.getResult();

    EXPECT_EQ(1, results.size());
    EXPECT_EQ("Rectangle (5.000, 3.000)", results[0]->info());
}