#ifndef FOLDER_H
#define FOLDER_H

#include "node.h"
#include "node_iterator.h"
#include <list>

class Folder : public Node
{
public:
    Folder(std::string id, std::string name) : Node(id, name)
    {
        _size = 0;
        _nodes = {};
    } // the default size of folder is zero.

    Folder(std::string id, std::string name, double size) : Node(id, name, size) {}
    // implement any functions inherit from Node that you think is suitable.
    double size() const
    {
        list<Node *>::const_iterator ptr;
        // return sum of all containing shapes area.
        double sizeN;
        for (sizeN = 0, ptr = _nodes.begin(); ptr != _nodes.end(); ptr++)
        {
            sizeN += (*ptr)->size();
        }
        return sizeN;
    }

    void updatePath(std::string path)
    {
        _path = path;
        list<Node *>::const_iterator ptr;
        // return sum of all containing shapes area.
        for (ptr = _nodes.begin(); ptr != _nodes.end(); ptr++)
        {
            (*ptr)->updatePath(_path + "/" + _name);
        }
    }

    void addNode(Node *node)
    {
        node->updatePath("/" + _name);
        _nodes.push_back(node);
    }

    Node *getNodeById(std::string id) const
    {
        list<Node *>::const_iterator ptr;
        for (ptr = _nodes.begin(); ptr != _nodes.end(); ptr++)
        {
            if ((*ptr)->id() == id)
            {
                return *ptr;
            }
            else
            {
                try
                {
                    return (*ptr)->getNodeById(id);
                }
                catch (std::string e)
                {
                }
            }
        }
        throw std::string("Expected get node but node not found.");
    }

    void deleteNodeById(std::string id)
    {
        list<Node *>::const_iterator ptr;
        //int deleteCount = 0;
        for (ptr = _nodes.begin(); ptr != _nodes.end(); ptr++)
        {
            if ((*ptr)->id() == id)
            {
                _nodes.erase(ptr);
                return;
                // return;
            }
            else // if ((*ptr)->color() == "transparent")
            {
                try
                {
                    (*ptr)->deleteNodeById(id);
                    return;
                }
                catch (std::string e)
                {
                }
                // if (deleteShapeInCompound(*ptr, id))
                //     return;
            }
        }
        throw std::string("Expected delete node but node not found.");
    }

    Iterator *createIterator() const
    {
        return new NodeIterator<std::list<Node *>::const_iterator>(_nodes.begin(), _nodes.end());
    }

private:
    std::list<Node *> _nodes;
};

#endif
