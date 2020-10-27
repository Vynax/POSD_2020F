#include "shape.h"
#include "iterator.h"

Shape *getShapeById(Shape *shape, std::string id)
{
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return a shape under the input shape tree sturcture that matches the id.
    // throw std::string "Only compound shape can get shape!" when the input shape is not iterable.
    // throw std::string "Expected get shape but shape not found" when no shape found with the given id.
    Iterator *itr = shape->createIterator();
    if (itr->isDone())
        shape->getShapeById("WTF");
    try
    {
        for (itr->first(); !itr->isDone(); itr->next())
        {
            if (itr->currentItem()->id() == id)
                return itr->currentItem();
            else
            {
                try
                {
                    return itr->currentItem()->getShapeById(id);
                }
                catch (std::string e)
                {
                }
            }
        }
    }
    catch (std::string e)
    {
    }

    throw std::string("Expected get shape but shape not found");
}

template <class Filter>
std::deque<Shape *> filterShape(Shape *shape, Filter filter)
{
    std::deque<Shape *> dq;
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return the shapes under the input shape tree sturcture that match the given filter.
    // throw std::string "Only compound shape can filter shape!" when the input shape is not iterable.
}

class AreaFilter
{
    AreaFilter(double upperBound, double lowerBound) {}
    bool operator()(Shape *shape) const {}
};

class PerimeterFilter
{
    PerimeterFilter(double upperBound, double lowerBound) {}
    bool operator()(Shape *shape) const {}
};

class ColorFilter
{
    ColorFilter(std::string color) {}
    bool operator()(Shape *shape) const {}
};

class TypeFilter
{
    TypeFilter(std::string type) {}
    bool operator()(Shape *shape) const {}
};
