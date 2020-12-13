#include "node.h"
#include <deque>
#include "node_scanner.h"
class NodeBuilder;
class NodeParser
{
public:
    NodeParser(std::string input)
    {
        // initialize a scanner for handling input.
        // initialize a node builder for handling building node.
        app_rule.push_back("(");
        app_rule.push_back("num");
        app_rule.push_back(")");
        nodescanner = NodeScanner(input);
        //cout << input << endl;
    }

    void parser()
    {
        // using NodeScanner::nextToken() to get all information to determine what to build,
        // and provide the argument the node needed.
        // use functions in NodeBuilder to build out the node.
        // the node with invalid argument should be ignored.
        string temp;
        try
        {
            while (nodescanner.input_size() >= 0)
            {
                temp = nodescanner.nextToken();
                if (temp == "}")
                    return;
                if (!nodescanner.str_AZ_az(temp))
                    continue;

                if (check_rule(app_rule))
                    nodebuilder.buildApp(temp, node_size);
                else
                {
                    string name = temp;
                    //cout << "name:" << temp << endl;
                    temp = nodescanner.nextToken();
                    //cout << temp << endl;
                    if (temp == "{")
                    {
                        nodebuilder.buildFolderBegin(name);
                        parser();
                        nodebuilder.buildFolderEnd();
                    }
                }
            }
        }
        catch (std::string s)
        {
            //cout << s << endl;
        }
    }

    bool check_rule(std::vector<string> rule)
    {
        int ptr_temp = nodescanner.get_ptr();
        std::string temp;
        for (size_t i = 0; i < rule.size(); i++)
        {
            temp = nodescanner.nextToken();
            if (rule.at(i) == "num")
            {
                if (nodescanner.isNum(temp))
                {
                    node_size = STD(temp);
                }
                else
                {
                    nodescanner.set_ptr(ptr_temp);
                    return false;
                }
            }
            else if (temp != rule.at(i))
            {
                nodescanner.set_ptr(ptr_temp);
                return false;
            }
        }
        return true;
    }

    std::deque<Node *> getResult()
    {
        // return result.
        return nodebuilder.getResult();
    }

private:
    NodeScanner nodescanner;
    NodeBuilder nodebuilder;
    double node_size;
    std::vector<string> app_rule;
    std::vector<string> folder_rule;
};
