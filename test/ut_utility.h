#include "../src/utility.h"

class UtilityTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        t345 = new Triangle("2", triangleVector, "red");
        e43 = new Ellipse("3", 4, 3, "blue");
        r34 = new Rectangle("4", 3, 4, "white");
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

TEST_F(UtilityTest, GetShapeById)
{
    std::list<Shape *> shapes = {t345};
    CompoundShape cs1("1", shapes);
    std::list<Shape *> shapes1 = {&cs1, e43, r34};
    CompoundShape cs0("0", shapes1);
    // cout << cs0.info() << endl;
    //cs0 = new CompoundShape;
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", getShapeById(&cs0, "2")->info());
}

TEST_F(UtilityTest, GetShapeByIdException)
{
    std::list<Shape *> shapes = {t345};
    CompoundShape cs1("1", shapes);
    std::list<Shape *> shapes1 = {&cs1, e43, r34};
    CompoundShape cs0("0", shapes1);
    // cout << cs0.info() << endl;
    //cs0 = new CompoundShape;
    try
    {
        getShapeById(&cs0, "5")->info();
        FAIL();
    }
    catch (std::string e)
    {
        EXPECT_EQ("Expected get shape but shape not found", e);
        //cout << e << endl;
    }
}

TEST_F(UtilityTest, AreaFilter)
{
    std::list<Shape *> shapes = {t345};
    CompoundShape cs1("1", shapes);
    std::list<Shape *> shapes1 = {&cs1, e43, r34};
    CompoundShape cs0("0", shapes1);
    // return shapes that area in range of 10 >= && 5 <=, but don't include compoundShape_0 itself.
    std::deque<Shape *> dq = filterShape(&cs0, AreaFilter(10, 5));
    std::deque<Shape *>::iterator itr = dq.begin();
    std::string str = "";
    while (itr != dq.end())
    {
        str += (*itr)->info();
        ++itr;
    }

    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", str);
}

TEST_F(UtilityTest, PerimeterFilter)
{
    std::list<Shape *> shapes = {t345};
    CompoundShape cs1("1", shapes);
    std::list<Shape *> shapes1 = {&cs1, e43, r34};
    CompoundShape cs0("0", shapes1);
    // return shapes that perimeter in range 10 >= && 5 <=, but don't include compoundShape_0 itself.
    std::deque<Shape *> dq = filterShape(&cs0, PerimeterFilter(10, 5));
    std::deque<Shape *>::iterator itr = dq.begin();
    std::string str = "";
    while (itr != dq.end())
    {
        str += (*itr)->info();
        ++itr;
    }

    EXPECT_EQ("", str);
}
TEST_F(UtilityTest, ColorFilter)
{
    std::list<Shape *> shapes = {t345};
    CompoundShape cs1("1", shapes);
    std::list<Shape *> shapes1 = {&cs1, e43, r34};
    CompoundShape cs0("0", shapes1);
    // return shapes that color match "white", but don't include compoundShape_0 itself.
    std::deque<Shape *> dq = filterShape(&cs0, ColorFilter("white"));
    std::deque<Shape *>::iterator itr = dq.begin();
    std::string str = "";
    while (itr != dq.end())
    {
        str += (*itr)->info();
        ++itr;
    }

    EXPECT_EQ("Rectangle (3.000, 4.000)", str);
}

TEST_F(UtilityTest, TypeFilter)
{
    std::list<Shape *> shapes = {t345};
    CompoundShape cs1("1", shapes);
    std::list<Shape *> shapes1 = {&cs1, e43, r34};
    CompoundShape cs0("0", shapes1);
    // return shapes that type match "Compound Shape", but don't include compoundShape_0 itself.
    std::deque<Shape *> dq = filterShape(&cs0, TypeFilter("Compound Shape"));
    std::deque<Shape *>::iterator itr = dq.begin();
    std::string str = "";
    while (itr != dq.end())
    {
        str += (*itr)->info();
        ++itr;
    }

    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", str);
}