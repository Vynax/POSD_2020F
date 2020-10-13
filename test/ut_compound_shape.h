#include "../src/compound_shape.h"
class CompoundTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        r34 = new Rectangle("0", 3, 4);
        e43 = new Ellipse("1", 4, 3);
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        t345 = new Triangle("2", triangleVector);
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
TEST_F(CompoundTest, Constructor)
{
    std::vector<Shape *> shapesVector;
    shapesVector.push_back(t345);
    shapesVector.push_back(r34);
    shapesVector.push_back(e43);
    CompoundShape cs("0", &shapesVector);
    //Shape *shapes[3] = {t345, r34, e43};
    EXPECT_EQ(6, shapesVector.at(0)->area());
    EXPECT_EQ(12, shapesVector.at(1)->area());
    EXPECT_NEAR(37.699, shapesVector.at(2)->area(), 0.001);
}

TEST_F(CompoundTest, Area)
{
    std::vector<Shape *> shapesVector;
    shapesVector.push_back(t345);
    shapesVector.push_back(r34);
    shapesVector.push_back(e43);
    CompoundShape cs("0", &shapesVector);
    //Shape *shapes[3] = {t345, r34, e43};
    EXPECT_NEAR(55.699, cs.area(), 0.001);
}

TEST_F(CompoundTest, Perimeter)
{
    std::vector<Shape *> shapesVector;
    shapesVector.push_back(t345);
    shapesVector.push_back(r34);
    shapesVector.push_back(e43);
    CompoundShape cs("0", &shapesVector);
    //Shape *shapes[3] = {t345, r34, e43};
    EXPECT_NEAR(48.849, cs.perimeter(), 0.001);
}

TEST_F(CompoundTest, Info)
{
    std::vector<Shape *> shapesVector;
    shapesVector.push_back(t345);
    shapesVector.push_back(r34);
    shapesVector.push_back(e43);
    CompoundShape cs("0", &shapesVector);
    //Shape *shapes[3] = {t345, r34, e43};
    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.000, 4.000), Ellipse (4.000, 3.000)}", cs.info());
}