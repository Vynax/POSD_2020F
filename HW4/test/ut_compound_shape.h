#include "../src/compound_shape.h"
class CompoundTest : public ::testing::Test
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
        //delete triangleVector;
    }
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    Shape *r34;
    Shape *e43;
    Shape *t345;
};
TEST_F(CompoundTest, Constructor)
{
    std::vector<Shape *> shapesVector = {t345, r34, e43};
    // shapesVector.push_back(t345);
    // shapesVector.push_back(r34);
    // shapesVector.push_back(e43);
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

TEST_F(CompoundTest, GetById)
{
    std::vector<Shape *> shapesVector;
    shapesVector.push_back(t345);
    shapesVector.push_back(r34);
    shapesVector.push_back(e43);
    CompoundShape cs("0", &shapesVector);
    //Shape *shapes[3] = {t345, r34, e43};
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", cs.getShapeById("2")->info());
}

TEST_F(CompoundTest, GetByIdException)
{
    std::vector<Shape *> shapesVector;
    shapesVector.push_back(t345);
    shapesVector.push_back(r34);
    shapesVector.push_back(e43);
    CompoundShape cs("0", &shapesVector);
    //Shape *shapes[3] = {t345, r34, e43};
    try
    {
        string s = cs.getShapeById("3")->info();
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("Expected get shape but shape not found", e);
    }
}

TEST_F(CompoundTest, DeleteById)
{
    std::vector<Shape *> shapesVector;
    shapesVector.push_back(t345);
    shapesVector.push_back(r34);
    shapesVector.push_back(e43);
    CompoundShape cs("0", &shapesVector);
    //Shape *shapes[3] = {t345, r34, e43};
    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.000, 4.000), Ellipse (4.000, 3.000)}", cs.info());
    cs.deleteShapeById("0");
    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Ellipse (4.000, 3.000)}", cs.info());
}

TEST_F(CompoundTest, DeleteByIdException)
{
    std::vector<Shape *> shapesVector;
    shapesVector.push_back(t345);
    shapesVector.push_back(r34);
    shapesVector.push_back(e43);
    CompoundShape cs("222", &shapesVector);
    //Shape *shapes[3] = {t345, r34, e43};
    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.000, 4.000), Ellipse (4.000, 3.000)}", cs.info());
    try
    {
        cs.deleteShapeById("55");
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("Expected delete shape but shape not found", e);
    }

    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.000, 4.000), Ellipse (4.000, 3.000)}", cs.info());
}

TEST_F(CompoundTest, DeleteInTripleLevel)
{
    std::vector<Shape *> shapesVector = {t345, r34, e43};
    CompoundShape cs1("s_0_1_2", &shapesVector);
    std::vector<Shape *> shapesV2 = {new Rectangle("12", 2.000, 6.000, "green"), new Rectangle("25", 5.000, 5.000, "white")};
    CompoundShape cs2("s_12_25", &shapesV2);
    std::vector<Shape *> shapesV3 = {&cs1, &cs2};
    CompoundShape cs3("cs3", &shapesV3);
    EXPECT_EQ("Compound Shape {Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.000, 4.000), Ellipse (4.000, 3.000)}, Compound Shape {Rectangle (2.000, 6.000), Rectangle (5.000, 5.000)}}", cs3.info());
    try
    {
        cs3.deleteShapeById("12");
    }
    catch (std::string e)
    {
    }
    EXPECT_EQ("Compound Shape {Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.000, 4.000), Ellipse (4.000, 3.000)}, Compound Shape {Rectangle (5.000, 5.000)}}", cs3.info());
}

TEST_F(CompoundTest, Exception)
{
    std::vector<Shape *> shapesVector;
    // shapesVector.push_back(t345);
    // shapesVector.push_back(r34);
    // shapesVector.push_back(e43);
    try
    {
        CompoundShape cs("0", &shapesVector); //==> the argument should > 0 or the rectangle can't be build.
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("This is not a compound shape!", e);
    }

    //Shape *shapes[3] = {t345, r34, e43};
}