#include "shape.h"
#include "two_dimensional_coordinate.h"

using namespace std;
class Triangle : public Shape
{
public:
    Triangle(std::vector<TwoDimensionalCoordinate *> vectors)
    {
        // If the triangle can't be successfully created,
        // handle the exception by throwing string "This is not a triangle!"
    }

    double area() const
    {
        // return the area of the Triangle.
        return 2.0;
    }

    double perimeter() const
    {
        // return the perimeter of the Triangle.
        return 3.0;
    }

    std::string info() const
    {
        // return the info of the Triangle.
        // ex. Triangle ([0.000, 0.000], [0.000, -3.141], [-4.000, 0.000])
        return "";
    }
};
