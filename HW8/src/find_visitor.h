#pragma once

#include "visitor.h"
#include "iterator.h"
#include <iostream>
#include <string>

class FindVisitor : public Visitor
{
public:
    FindVisitor(std::string name) : _name(name) {}

    void visitApp(App *app)
    {
        // find app when app's name matches given name,
        // add app's route as result.
        if (_name == app->name())
            _result += app->route() + "\n";
    }

    void visitFolder(Folder *folder)
    {
        // find folder when folder's name matches given name,
        // add folder's route as result.
        // And find the tree structure bellow,
        // add the other match result with `\n`.
        if (_name == folder->name())
            _result += folder->route() + "\n";
        Iterator *it = folder->createIterator();
        it->first();
        //cout << "_name:" << _name << endl;
        //cout << it->currentItem()->name() << endl;
        bool in_or_not = false;
        while (!it->isDone())
        {
            in_or_not = true;
            //cout << "_name:" << _name << endl;
            //cout << it->currentItem()->name() << endl;
            /*if (it->currentItem()->name() == _name)
                _result += it->currentItem()->route() + "\n";*/
            it->currentItem()->accept(this);
            it->next();
        }
        /*if (in_or_not)
            _result = _result.substr(0, _result.size() - 1);*/
    }

    std::string getResult() const
    {
        // return result.
        //if (_result[_result.size()] == '\n')
        std::string s = _result.substr(0, _result.size() - 1);

        return s;
    }

private:
    std::string _result;
    std::string _name;
};
