#include "shape.h"
#include <stack>
class Rectangle;
class Ellipse;
class Triangle;
class CompoundShape;

class ShapeBuilder
{
public:
    ShapeBuilder() {}

    void buildRectangle(double length, double width)
    {
        // build a rectangle with an unique id and push in a std::stack.
        _stack.push(new Rectangle(std::to_string(id), length, width));
        id++;
    }

    void buildEllipse(double semiMajorAxes, double semiMinorAxes)
    {
        // build a ellipse with an unique id and push in a std::stack.
        _stack.push(new Ellipse(std::to_string(id), semiMajorAxes, semiMinorAxes));
        id++;
    }

    void buildTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        // build a triangle with an unique id and push in a std::stack.
        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(x1, y1));
        triangleVector.push_back(new TwoDimensionalCoordinate(x2, y2));
        triangleVector.push_back(new TwoDimensionalCoordinate(x3, y3));
        _stack.push(new Triangle(std::to_string(id), triangleVector));
        id++;
    }

    void buildCompoundShapeBegin()
    {
        // for notifing beginning of a Compound Shape.
        _stack.push(new CompoundShape(std::to_string(id)));
        id++;
    }

    void buildCompoundShapeEnd()
    {
        // for notifing ending of a Compound Shape.
        std::list<Shape *> l;
        while (!dynamic_cast<CompoundShape *>(_stack.top()) ||
               (dynamic_cast<CompoundShape *>(_stack.top()) && !_stack.top()->createIterator()->isDone()))
        {
            l.push_back(_stack.top());
            _stack.pop();
        }
        for (auto it = l.rbegin(); it != l.rend(); it++)
        {
            _stack.top()->addShape(*it);
        }
    }

    std::deque<Shape *> getResult()
    {
        std::deque<Shape *> result;
        // return result.
        while (!_stack.empty())
        {
            result.push_back(_stack.top());
            _stack.pop();
        }
        return std::deque<Shape *>(result.rbegin(), result.rend());
    }

private:
    std::stack<Shape *> _stack;
    int id = 0;
};
