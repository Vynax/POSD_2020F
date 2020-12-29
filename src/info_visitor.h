#ifndef INFO_VISITOR_H
#define INFO_VISITOR_H

#include "visitor.h"
#include <vector>
class Ellipse;
class Triangle;
class Rectangle;
class CompoundShape;

class InfoVisitor : public Visitor
{
public:
    void visit(Ellipse *ellipse)
    {
        // create info of ellipse, same way as ellipse->info().
        // DO NOT use ellipse->info() to get info directly.
        // you may add public function for Ellipse to get it's data members.
        _info = "Ellipse (" + DTS(ellipse->getSemiMajorAxes(), 3) + ", " + DTS(ellipse->getSemiMinorAxes(), 3) + ")";
    }

    void visit(Triangle *triangle)
    {
        // create info of ellipse, same way as triangle->info().
        // DO NOT use triangle->info() to get info directly.
        // you may add public function for Triangle to get it's data members.
        vector<TwoDimensionalCoordinate *> vectors = triangle->getVectors();
        int i, size = vectors.size();
        _info = "";
        _info += "Triangle (";
        for (i = 0; i < size; i++)
        {
            _info += "[";
            _info += DTS(vectors[i]->getX(), 3);
            _info += ", ";
            _info += DTS(vectors[i]->getY(), 3);
            _info += "]";
            if (i < size - 1) //三個座標之間有兩個空白
                _info += ", ";
        }
        _info += ")";
    }

    void visit(Rectangle *rectangle)
    {
        // create info of rectangle, same way as rectangle->info().
        // DO NOT use rectangle->info() to get info directly.
        // you may add public function for Rectangle to get it's data members.
        _info = "Rectangle (" + DTS(rectangle->getLength(), 3) + ", " + DTS(rectangle->getWidth(), 3) + ")";
    }

    void visit(CompoundShape *compoundShape)
    {
        // create info of compoundShape, same way as compoundShape->info().
        // DO NOT use compoundShape->info() to get info directly.
        // you may add public function for CompoundShape to get it's data members.
        std::list<Shape *> shapes = compoundShape->getShapes();
        std::list<Shape *>::const_iterator ptr;
        InfoVisitor *iv = new InfoVisitor();
        _info = "Compound Shape {";
        for (ptr = shapes.begin(); ptr != shapes.end(); ptr++)
        {
            (*ptr)->accept(iv);
            _info += iv->info();
            if (ptr != --(shapes.end()))
                _info += ", ";
        }
        _info += "}";
    }

    std::string info() const
    {
        // return info;
        return _info;
    }

private:
    string _info;
};

#endif