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
    // access the shape with iterator pattern.
    // DO NOT use Type Checking or Dynamic Type that would violate OCP to implement the function.
    // return the shapes under the input shape tree sturcture that match the given filter.
    // throw std::string "Only compound shape can filter shape!" when the input shape is not iterable.
    std::deque<Shape *> _dq;
    try
    {
        Iterator *itr = shape->createIterator();
        Shape *now;
        for (itr->first(); !itr->isDone(); itr->next())
        {
            now = itr->currentItem();
            if (filter(now))
            {
                _dq.push_back(now);
            }
            try
            {
                std::deque<Shape *> dq_catch = filterShape(now, filter);
                _dq.insert(_dq.end(), dq_catch.begin(), dq_catch.end());
            }
            catch (std::string e)
            {
            }
        }
    }
    catch (std::string e)
    {
        throw std::string("Only compound shape can filter shape!");
    }
    return _dq;
}

class AreaFilter
{
public:
    AreaFilter(double upperBound, double lowerBound) : _upperBound(upperBound), _lowerBound(lowerBound) {}
    bool operator()(Shape *shape) const
    {
        if (shape->area() <= _upperBound && shape->area() >= _lowerBound)
            return true;
        else
            return false;
        return 0;
    }

private:
    double _upperBound, _lowerBound;
};

class PerimeterFilter
{
public:
    PerimeterFilter(double upperBound, double lowerBound) : _upperBound(upperBound), _lowerBound(lowerBound) {}
    bool operator()(Shape *shape) const
    {
        if (shape->perimeter() <= _upperBound && shape->perimeter() >= _lowerBound)
            return true;
        else
            return false;
        return 0;
    }

private:
    double _upperBound, _lowerBound;
};

class ColorFilter
{
public:
    ColorFilter(std::string color) : _color(color) {}
    bool operator()(Shape *shape) const
    {
        if (shape->color() == _color)
            return true;
        else
            return false;
        return 0;
    }

private:
    std::string _color;
};

class TypeFilter
{
public:
    TypeFilter(std::string type) : _type(type) {}
    bool operator()(Shape *shape) const
    {
        if (shape->type() == _type)
            return true;
        else
            return false;
        return 0;
    }

private:
    std::string _type;
};
