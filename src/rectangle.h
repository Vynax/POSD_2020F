#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "visitor.h"

class Rectangle : public Shape
{
private:
    //data members
    double _length, _width;

public:
    Rectangle(std::string id, double length, double width) : Shape(id), _length(length), _width(width)
    {
        if (length <= 0 || width <= 0)
            throw std::string("This is not a rectangle!");
        // _id = id;
        // _color = "white";
    }
    Rectangle(std::string id, double length, double width, std::string color) : Shape(id, color), _length(length), _width(width)
    {
        // If the rectangle can't be successfully created,
        // handle the exception by throwing string "This is not a rectangle!"
        if (length <= 0 || width <= 0)
            throw std::string("This is not a rectangle!");
        // _length = length;
        // _width = width;
        // _id = id;
        // _color = color;
    }

    void accept(Visitor *visitor)
    {
        (*visitor).visit(this);
    }

    double getLength()
    {
        return _length;
    }

    double getWidth()
    {
        return _width;
    }

    double area() const
    {
        // return the area of the Rectangle.
        return _length * _width;
    }

    double perimeter() const
    {
        // return the perimeter of the Rectangle.
        return (_length + _width) * 2;
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

    std::string type() const
    {
        return "Rectangle";
    }
};

#endif