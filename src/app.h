#ifndef APP_H
#define APP_H

#include "node.h"

class App : public Node
{
public:
    App(std::string id, std::string name) : Node(id, name) {}

    App(std::string id, std::string name, double size) : Node(id, name, size) {}

    double size() const { return _size; }

    void updatePath(std::string path) { _path = path; }

    // implement any functions inherit from Node that you think is suitable.
};

#endif