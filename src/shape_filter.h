#pragma once

#include <list>
#include "filter.h"

template <class Predicate>
class ShapeFilter : public Filter
{
public:
    ShapeFilter(Predicate pred) : _pred(pred) {}
    // `Predicate` is a template name for lambda,
    //  you may use your own name.

    Filter *setNext(Filter *filter)
    {
        // seeting next filter.
        return new ShapeFilter(_pred);
    }

    std::list<Shape *> push(std::list<Shape *> shapes)
    {
        // push down filtered data and return result.
        return shapes;
    }

private:
    Predicate _pred;
};
