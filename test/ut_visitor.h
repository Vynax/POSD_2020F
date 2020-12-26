#include "../src/area_visitor.h"
#include "../src/info_visitor.h"

class VisitorTest : public ::testing::Test
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

TEST_F(VisitorTest, VisitorArea)
{
    std::list<Shape *> shapes = {t345};
    CompoundShape cs1("1", shapes);
    std::list<Shape *> shapes1 = {&cs1, e43, r34};
    CompoundShape cs0("0", shapes1);

    AreaVisitor *av = new AreaVisitor();
    e43->accept(av);
    EXPECT_NEAR(37.699, av->area(), 0.001);
    t345->accept(av);
    EXPECT_NEAR(6, av->area(), 0.001);
    r34->accept(av);
    EXPECT_EQ(12, av->area());
    cs0.accept(av);
    EXPECT_NEAR(55.699, av->area(), 0.001);
    //cout << "hi" << endl;
}

TEST_F(VisitorTest, VisitorInfo)
{
    std::list<Shape *> shapes = {t345};
    CompoundShape cs1("1", shapes);
    std::list<Shape *> shapes1 = {&cs1, e43, r34};
    CompoundShape cs0("0", shapes1);

    InfoVisitor *iv = new InfoVisitor();
    e43->accept(iv);
    EXPECT_EQ("Ellipse (4.000, 3.000)", iv->info());
    t345->accept(iv);
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", iv->info());
    r34->accept(iv);
    EXPECT_EQ("Rectangle (3.000, 4.000)", iv->info());

    cs0.accept(iv);
    EXPECT_EQ("Compound Shape {Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}, Ellipse (4.000, 3.000), Rectangle (3.000, 4.000)}", iv->info());
}