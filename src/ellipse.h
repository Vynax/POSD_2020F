#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"
#include <math.h>

using namespace std;

class Ellipse : public Shape
{
private:
    //data members
    double _semiMajorAxes, _semiMinorAxes;

public:
    Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes) : Shape(id)
    {
        // If the ellipse can't be successfully created,
        // handle the exception by throwing string "This is not an ellipse!"
        //如果橢圓的長半徑小於短半徑，或是兩者其一為零，回傳錯誤資訊
        if (semiMajorAxes <= 0 || semiMinorAxes <= 0 || semiMajorAxes < semiMinorAxes)
            throw std::string("This is not an ellipse!");
        _semiMajorAxes = semiMajorAxes;
        _semiMinorAxes = semiMinorAxes;
        _id = id;
        _color = "white";
    }
    Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes, std::string color) : Shape(id, color)
    {
        // If the ellipse can't be successfully created,
        // handle the exception by throwing string "This is not an ellipse!"
        //如果橢圓的長半徑小於短半徑，或是兩者其一為零，回傳錯誤資訊
        if (semiMajorAxes <= 0 || semiMinorAxes <= 0 || semiMajorAxes < semiMinorAxes)
            throw std::string("This is not an ellipse!");
        _id = id;
        _color = color;
        _semiMajorAxes = semiMajorAxes;
        _semiMinorAxes = semiMinorAxes;
    }

    double area() const
    {
        // return the area of the Ellipse.
        return RTD(M_PI * _semiMajorAxes * _semiMinorAxes, 3);
    }

    double perimeter() const
    {
        // return the perimeter of the Ellipse.
        // L=2πb+4(a-b)
        return 2 * M_PI * _semiMinorAxes + 4 * (_semiMajorAxes - _semiMinorAxes);
    }

    string info() const
    {
        // return the info of the Ellipse.
        // ex. Ellipse (3.712, 4.000)
        return "Ellipse (" + DTS(_semiMajorAxes, 3) + ", " + DTS(_semiMinorAxes, 3) + ")";
    }

    void addShape(Shape *shape)
    {
        throw std::string("Only compound shape can add shape!");
    }
    void deleteShapeById(std::string id)
    {
        throw std::string("Only compound shape can delete shape!");
    }
    Shape *getShapeById(std::string id)
    {
        throw std::string("Only compound shape can get shape!");
    }
};

#endif