//#include "shape.h"
#include "iterator.h"
#include "node.h"
#include <deque>

template <class Filter>
std::deque<Node *> filterNode(Node *node, Filter filter)
{
    std::deque<Node *> _dq;
    try
    {
        Iterator *itr = node->createIterator();
        Node *now;
        for (itr->first(); !itr->isDone(); itr->next())
        {
            now = itr->currentItem();
            if (filter(now))
            {
                _dq.push_back(now);
            }
            try
            {
                std::deque<Node *> dq_catch = filterNode(now, filter);
                _dq.insert(_dq.end(), dq_catch.begin(), dq_catch.end());
            }
            catch (std::string e)
            {
            }
        }
    }
    catch (std::string e)
    {
        throw std::string("Only folder can filter node!");
    }
    return _dq;
}

class SizeFilter
{
public:
    SizeFilter(double upperBound, double lowerBound) : _upperBound(upperBound), _lowerBound(lowerBound) {}
    bool operator()(Node *node) const
    {
        if (node->size() <= _upperBound && node->size() >= _lowerBound)
            return true;
        else
            return false;
        return 0;
    }

private:
    double _upperBound, _lowerBound;
};
