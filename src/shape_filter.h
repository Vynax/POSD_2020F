#pragma once

#include <list>
#include "filter.h"
#include <functional>
//template <class FilterFunction>
//typedef bool (*FilterFunction)(Shape *);
typedef std::function<bool(Shape *)> FilterFunction;
class ShapeFilter : public Filter
{
public:
    // `Predicate` is a template name for lambda,
    //  you may use your own name.
    ShapeFilter(FilterFunction pred) : _filterf(pred)
    {
        next_filter = nullptr;
    }

    Filter *setNext(Filter *filter)
    {
        // setting next filter.
        next_filter = filter;
        return filter;
    }

    std::list<Shape *> push(std::list<Shape *> shapes)
    {
        // push down filtered data and return result.
        std::list<Shape *>::const_iterator ptr;
        // cout << "hi" << endl;
        for (ptr = shapes.begin(); ptr != shapes.end(); ptr++)
        {
            if (_filterf(*ptr))
                _shapes.push_back(*ptr);
            // cout << "hi2" << endl;
        }

        // cout << "hi3" << endl;
        if (next_filter == nullptr)
            return _shapes;
        else
            return next_filter->push(_shapes);
    }

private:
    FilterFunction _filterf;
    std::list<Shape *> _shapes;
    Filter *next_filter;
};
