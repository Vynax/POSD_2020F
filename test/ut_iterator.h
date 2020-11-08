#include "../src/null_iterator.h"

class IteratorTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        r34 = new Rectangle("0", 3, 4, "yellow");
        e43 = new Ellipse("1", 4, 3, "blue");
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        t345 = new Triangle("2", triangleVector, "red");
    }

    void TearDown() override
    {
        delete r34;
        delete e43;
        delete t345;
        triangleVector.clear();
        triangleVector.shrink_to_fit();
    }
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    Shape *r34;
    Shape *e43;
    Shape *t345;
};

TEST_F(IteratorTest, Else_Type)
{
    std::list<Shape *> shapes = {t345, r34, e43};
    CompoundShape cs("0", shapes);
    EXPECT_EQ("Rectangle", r34->type());
    EXPECT_EQ("Ellipse", e43->type());
    EXPECT_EQ("Triangle", t345->type());
    EXPECT_EQ("Compound Shape", cs.type());
}

TEST_F(IteratorTest, NullIterator)
{
    try
    {
        r34->createIterator()->first();
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("No child member!", e);
    }
    EXPECT_EQ(r34->createIterator()->isDone(), true);
    try
    {
        e43->createIterator()->next();
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("No child member!", e);
    }
    EXPECT_EQ(e43->createIterator()->isDone(), true);
    try
    {
        t345->createIterator()->currentItem();
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("No child member!", e);
    }
    EXPECT_EQ(t345->createIterator()->isDone(), true);
}

TEST_F(IteratorTest, ShapeIterator)
{
    std::list<Shape *> shapes = {t345, r34, e43};
    CompoundShape cs("0", shapes);
    Iterator *si = cs.createIterator();
    EXPECT_EQ(6, si->currentItem()->area());
    si->next();
    EXPECT_EQ(12, si->currentItem()->area());
    si->next();
    EXPECT_NEAR(37.699, si->currentItem()->area(), 0.001);
    try
    {
        si->next();
        si->next();
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("Moving past the end!", e);
    }
}