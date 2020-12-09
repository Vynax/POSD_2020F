#include <deque>
#include "node.h"
#include <stack>
class App;
class Folder;

class NodeBuilder
{
public:
    void buildApp(std::string name, double size)
    {
        // build a app with an unique id and push in a std::stack.
        _stack.push(new App(std::to_string(id), name, size));
        id++;
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
        // return result.
        while (!_stack.empty())
        {
            result.push_back(_stack.top());
            _stack.pop();
        }
        return std::deque<Node *>(result.rbegin(), result.rend());
    }

private:
    std::stack<Node *> _stack;
    int id = 0;
};
