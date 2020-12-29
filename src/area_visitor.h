#ifndef AREA_VISITOR_H
#define AREA_VISITOR_H

#include <math.h>
#include "visitor.h"
class Ellipse;
class Triangle;
class Rectangle;
class CompoundShape;

class AreaVisitor : public Visitor
{
public:
    void visit(Ellipse *ellipse)
    {
        // caculate the area of Ellipse.
        // DO NOT use ellipse->area() to get area directly.
        // you may add public function for Ellipse to get it's data members.
        _area = M_PI * (*ellipse).getSemiMajorAxes() * (*ellipse).getSemiMinorAxes();
    }

    void visit(Triangle *triangle)
    {
        // caculate the area of Triangle.
        // DO NOT use triangle->area() to get area directly.
        // you may add public function for Triangle to get it's data members.
        double *length = triangle->getLength();
        double a = length[0];
        double b = length[1];
        double c = length[2];
        double s = (a + b + c) / 2;

        _area = sqrt(s * (s - a) * (s - b) * (s - c)); //海龍公式
    }

    void visit(Rectangle *rectangle)
    {
        // caculate the area of Rectangle.
        // DO NOT use rectangle->area() to get area directly.
        // you may add public function for Rectangle to get it's data members.
        _area = rectangle->getLength() * rectangle->getWidth();
    }

    void visit(CompoundShape *compoundShape)
    {
        // caculate the area of CompoundShape.
        // DO NOT use compoundShape->area() to get area directly.
        // you may add public function for CompoundShape to get it's data members.
        std::list<Shape *> shapes = compoundShape->getShapes();
        std::list<Shape *>::const_iterator ptr;
        AreaVisitor *av = new AreaVisitor();
        // return sum of all containing shapes area.
        for (_area = 0, ptr = shapes.begin(); ptr != shapes.end(); ptr++)
        {
            (*ptr)->accept(av);
            _area += av->area();
        }
    }

    double area() const
    {
        // return area;
        return _area;
    }

private:
    double _area;
};

#endif