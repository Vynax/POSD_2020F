#include <deque>
#include "node.h"

class NodeBuilder
{
public:
    void buildApp(std::string name, double size)
    {
        // build a app with an unique id and push in a std::stack.
    }

    void buildFolderBegin(std::string name)
    {
        // notify begin of folder.
    }

    void buildFolderEnd()
    {
        // notify end of folder.
    }

    std::deque<Node *> getResult()
    {
        // return result.
        std::deque<Node *> result;
        return result;
    }
};
