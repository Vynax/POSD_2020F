#ifndef TWODC_H
#define TWODC_H

#include "shape.h"

class TwoDimensionalCoordinate
{

private:
    double _x, _y;

public:
    TwoDimensionalCoordinate(double x, double y)
    {
        _x = x;
        _y = y;
    }

    double getX()
    {
        // return x;
        //return RTD(_x, 3);
        return _x;
    }

    double getY()
    {
        // return y;
        //return RTD(_y, 3);
        return _y;
    }
};

#endif