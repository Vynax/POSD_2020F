#include "node.h"
#include "null_iterator.h"

Node::Node(std::string id, std::string name) : _id(id), _name(name)
{
    _path = "";
    null_itr = new NullIterator();
    _size = 0;
}

Node::Node(std::string id, std::string name, double size) : _id(id), _name(name), _size(size)
{
    _path = "";
    null_itr = new NullIterator();
}

void Node::addNode(Node *node)
{
    throw std::string("only folder can add node.");
}

Node *Node::getNodeById(std::string id) const
{
    throw std::string("only folder can get node.");
}

void Node::deleteNodeById(std::string id)
{
    throw std::string("only folder can delete node.");
}

Iterator *Node::createIterator() const
{
    return null_itr;
}

Node::~Node() {}