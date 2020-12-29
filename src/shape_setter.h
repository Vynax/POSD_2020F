#pragma once

#include <list>
#include "filter.h"
#include <functional>

typedef std::function<void(Shape *)> FilterFunction1;
class ShapeSetter : public Filter
{
public:
    // `Predicate` is a template name for lambda,
    //  you may use your own name.
    ShapeSetter(FilterFunction1 pred) : _filterf(pred)
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
        for (ptr = shapes.begin(); ptr != shapes.end(); ptr++)
        {
            _filterf(*ptr);
            // std::cout << "hi4" << std::endl;
        }

        // std::cout << "hi5" << std::endl;
        if (next_filter == nullptr)
        {
            // std::cout << "hi6" << std::endl;
            return shapes;
        }
        else
        {
            // std::cout << "hi7" << std::endl;
            return next_filter->push(shapes);
        }
    }

private:
    FilterFunction1 _filterf;
    Filter *next_filter;
};