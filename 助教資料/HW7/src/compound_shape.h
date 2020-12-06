#ifndef COMPOUND_SHAPE_H
#define COMPOUND_SHAPE_H

#include "shape.h"
#include "rectangle.h"
#include "shape_iterator.h"
#include <list>

class CompoundShape : public Shape
{

public:
    CompoundShape(std::string id, string color = "transparent") : Shape(id, color)
    {
        // The default color of compound shape should be "transparent".
    }

    CompoundShape(std::string id, std::list<Shape *> shapes, string color = "transparent") : Shape(id, color), _shapes(shapes)
    {
        // The default color of compound shape should be "transparent".
        /* if (_shapes.size() == 0)
            throw std::string("This is not a compound shape!"); */
        // When there's no shape contain in the compound shape,
        // should throw std::string "This is not a compound shape!"
    }

    std::list<Shape *> getShapes()
    {
        return _shapes;
    }

    void accept(Visitor *visitor)
    {
        (*visitor).visit(this);
    }

    double area() const
    {
        list<Shape *>::const_iterator ptr;
        // return sum of all containing shapes area.
        double areaN;
        for (areaN = 0, ptr = _shapes.begin(); ptr != _shapes.end(); ptr++)
        {
            areaN += (*ptr)->area();
        }
        return areaN;
    }

    double perimeter() const
    {
        list<Shape *>::const_iterator ptr;
        // return sum of all containing shapes perimeter.
        double perimeterN;
        for (perimeterN = 0, ptr = _shapes.begin(); ptr != _shapes.end(); ptr++)
        {
            perimeterN += (*ptr)->perimeter();
        }
        return perimeterN;
    }

    std::string info() const
    {
        // return list of all containing shapes info with wrapped of "CompoundShape {}".
        // ex."Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}"
        std::string str("Compound Shape {");
        list<Shape *>::const_iterator ptr;
        for (ptr = _shapes.begin(); ptr != _shapes.end(); ptr++)
        {
            str += (*ptr)->info();
            if (ptr != --(_shapes.end()))
                str += ", ";
        }
        str += "}";
        return str;
    }

    void addShape(Shape *shape)
    {
        // add shape into compound shape.
        _shapes.push_back(shape);
    }

    void deleteShapeById(std::string id)
    {
        // search and delete a shape through id,
        // search all the containing shapes and the tree structure below,
        // if no match of id, throw std::string "Expected delete shape but shape not found"
        list<Shape *>::const_iterator ptr;
        //int deleteCount = 0;
        for (ptr = _shapes.begin(); ptr != _shapes.end(); ptr++)
        {
            if ((*ptr)->id() == id)
            {
                _shapes.erase(ptr);
                return;
                // return;
            }
            else // if ((*ptr)->color() == "transparent")
            {
                try
                {
                    (*ptr)->deleteShapeById(id);
                    return;
                }
                catch (std::string e)
                {
                }
                // if (deleteShapeInCompound(*ptr, id))
                //     return;
            }
        }
        throw std::string("Expected delete shape but shape not found");
    }

    Shape *getShapeById(std::string id) const
    {
        // search and return a shape through id,
        // search all the containing shapes and the tree structure below,
        // if no match of id, throw std::string "Expected get shape but shape not found"
        //return (Shape *)(new Rectangle("0", 3, 4));
        list<Shape *>::const_iterator ptr;
        for (ptr = _shapes.begin(); ptr != _shapes.end(); ptr++)
        {
            if ((*ptr)->id() == id)
            {
                return *ptr;
            }
            else
            {
                try
                {
                    return (*ptr)->getShapeById(id);
                }
                catch (std::string e)
                {
                }
            }
        }
        throw std::string("Expected get shape but shape not found");
    }
    std::string type() const
    {
        return "Compound Shape";
    }

    Iterator *createIterator() const
    {
        // return ShapeIterator
        return new ShapeIterator<std::list<Shape *>::const_iterator>(_shapes.begin(), _shapes.end());
    }

protected:
    std::list<Shape *> _shapes;

    // int deleteShapeInCompound(Shape *CS, std::string id)
    // {
    //     vector<Shape *>::iterator ptr;
    //     int deleteCount = 0;
    //     for (ptr = CS->_shapes->begin(); ptr < CS->_shapes->end(); ptr++)
    //     {
    //         if ((*ptr)->id() == id)
    //         {
    //             CS->_shapes->erase(ptr);
    //             deleteCount++;
    //             // return true;
    //         }
    //         else if ((*ptr)->color() == "transparent")
    //         {
    //             // if (deleteShapeInCompound(*ptr, id))
    //             //     return true;
    //             deleteCount += (deleteShapeInCompound(*ptr, id));
    //         }
    //     }

    //     return deleteCount;
    // }
};

#endif