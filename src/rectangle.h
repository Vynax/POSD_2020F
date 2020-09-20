#include "shape.h"

using namespace std;

class Rectangle : public Shape
{
public:
    Rectangle(double length, double width)
    {
        // If the rectangle can't be successfully created,
        // handle the exception by throwing string "This is not a rectangle!"

        _length = length;
        _width = width;
    }

    double area() const
    {
        // return the area of the Rectangle.
        return RTD(_length * _width, 3);
    }

    double perimeter() const
    {
        // return the perimeter of the Rectangle.
        return RTD((_length + _width) * 2, 3);
    }

    std::string info() const
    {
        // return the info of the Rectangle.
        // ex. Rectangle (3.712, 4.000)
        /*string s;
        s = "Rectangle (" + DTS(_length, 3);
        s = s + ", " + DTS(_width, 3) + ")";*/
        return "Rectangle (" + DTS(_length, 3) + ", " + DTS(_width, 3) + ")";
    }

private:
    //data members
    double _length, _width;
};
