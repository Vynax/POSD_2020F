#include "shape.h"
#include <math.h>

using namespace std;

class Ellipse : public Shape
{
private:
    //data members
    double _semiMajorAxes, _semiMinorAxes;

public:
    Ellipse(double semiMajorAxes, double semiMinorAxes)
    {
        // If the ellipse can't be successfully created,
        // handle the exception by throwing string "This is not a ellipse!"
        _semiMajorAxes = semiMajorAxes;
        _semiMinorAxes = semiMinorAxes;
    }

    double area() const
    {
        // return the area of the Ellipse.
        //return RTD(M_PI * _semiMajorAxes * _semiMinorAxes, 3);
        return 2.0;
    }

    double perimeter() const
    {
        // return the perimeter of the Ellipse.
        // L=2πb+4(a-b)
        //return RTD(2 * M_PI * _semiMinorAxes + 4 * (_semiMajorAxes - _semiMinorAxes), 3);
        return 3.0;
    }

    std::string info() const
    {
        // return the info of the Ellipse.
        // ex. Ellipse (3.712, 4.000)
        //return "Ellipse (" + DTS(_semiMajorAxes, 3) + ", " + DTS(_semiMinorAxes, 3) + ")";
        return "";
    }
};
