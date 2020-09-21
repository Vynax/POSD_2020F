#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "tritest.h"
#include "shape.h"
#include "two_dimensional_coordinate.h"
#include <math.h>

//class Tritest(vector<TwoDimensionalCoordinate *> aaa){};
class Triangle : public Shape
{
private:
    vector<TwoDimensionalCoordinate *> _vectors;
    Tritest *tritest;

public:
    Triangle(std::vector<TwoDimensionalCoordinate *> vectors)
    {
        // If the triangle can't be successfully created,
        // handle the exception by throwing string "This is not a triangle!"
        _vectors = vectors;
        tritest = new Tritest(_vectors);
        if (!(tritest->triangletest())) //如果triangletest失敗就回傳錯誤資訊
            throw string("This is not a triangle!");
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
        int i, j;
        string s;
        s += "Triangle (";
        for (i = 0; i < _vectors.size(); i++)
        {
            s += "[";
            for (j = 0; j < 2; j++)
            {
            }
            s += "]";
        }
        return "Triangle ([";
    }
};

#endif