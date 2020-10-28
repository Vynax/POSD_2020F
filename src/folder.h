#ifndef FOLDER_H
#define FOLDER_H

#include "node.h"
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

private:
    std::list<Node *> _nodes;
};

#endif
