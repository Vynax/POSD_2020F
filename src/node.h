#ifndef NODE_H
#define NODE_H

#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

class Iterator;
class Node
{
protected:
    std::string _id, _name, _path;
    double _size;
    Iterator *null_itr;

public:
    Node(std::string id, std::string name);
    Node(std::string id, std::string name, double size);
    std::string id() const { return _id; };
    std::string name() const { return _name; };

    std::string route() const { return _path + "/" + _name; }; // the "virtual" of this funtion is optional.
    virtual double size() const;
    virtual void updatePath(std::string path);

    virtual void addNode(Node *node);
    virtual Node *getNodeById(std::string id) const;
    virtual void deleteNodeById(std::string id);
    virtual Iterator *createIterator() const;
    virtual ~Node();
};

#endif