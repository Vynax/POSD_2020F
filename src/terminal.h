#include <regex>
#include <iostream>
#include "sort.h"
#include "shape.h"
#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"
#include "two_dimensional_coordinate.h"

using namespace std;
class Terminal
{
protected:
    std::smatch _match;
    stringstream ss;
    vector<string> rule;
    string str = "";
    std::string num = "-?\\d+(\\.\\d+)?";

    vector<string> vec;
    vector<Shape *> shapes;
    std::regex pattern;
    double value[6];
    size_t found;

    vector<TwoDimensionalCoordinate *> triangleVector;
    Shape *s;
    string type[2]; // 0是area or perimeter，1是 inc or dec
public:
    Terminal(std::string input)
    {
        std::string space(" ");
        ss.str("");
        ss.clear();
        std::cout << input << std::endl;
        rule.push_back("");
        rule.push_back("((Rectangle|Ellipse) +\\( *" + num + " *, *" + num + " *\\)) *");
        rule.push_back("|(Triangle +( *\\(( *\\[ *" + num + " *, *" + num + " *\\] *,){2}( *\\[ *" + num + " *, *" + num + " *\\] *\\))))");
        rule.push_back("|(area|perimeter) *");
        rule.push_back("|(inc|dec) *");
        for (int i = 1; i < rule.size(); i++)
            rule.at(0) += rule.at(i);
        std::string stri = input;
        pattern.assign(rule.at(0), std::regex::ECMAScript);
        std::regex_search(input, _match, pattern);
        //str1 = _match[0];
        int i = 0;
        int final_amount = 0;
        // .* [area|perimeter] [inc|dec]
        //int shape_amount = 0;
        int count[3] = {0}; // 0是形狀數量，1是是否有area or perimeter，2是是否有升冪或降冪
        while (regex_search(stri, _match, pattern))
        {
            // cout << "\nMatched string is " << _match.str(0) << endl
            //      << "and it is found at position "
            //      << _match.position(0) << endl;
            vec.push_back(_match.str(0));
            if (vec.at(i).find("Rectangle") != std::string::npos || vec.at(i).find("Ellipse") != std::string::npos || vec.at(i).find("Triangle") != std::string::npos)
                count[0]++;
            else if (vec.at(i).find("area") != std::string::npos)
            {
                count[1]++;
                type[0] = "area";
            }
            else if (vec.at(i).find("perimeter") != std::string::npos)
            {
                count[1]++;
                type[0] = "perimeter";
            }
            else if (vec.at(i).find("inc") != std::string::npos)
            {
                count[2]++;
                type[1] = "inc";
            }
            else if (vec.at(i).find("dec") != std::string::npos)
            {
                count[2]++;
                type[1] = "dec";
            }
            // suffix to find the rest of the string.
            i++;
            stri = _match.suffix().str();
        }
        for (i = 0; i < 3; i++)
        {
            if (count[i] == 0)
                throw string("invalid input");
        }
        /*for (int i = 0; i < _match.size(); i++)
        {
            //std::cout << "i";
            std::cout << _match[i] << std::endl;
        }*/
        cout << "vecsize=" << vec.size() << endl;
        cout << "shapecount=" << count[0] << endl;
        pattern.assign(num);
        for (int i = 0, final_amount = 0; i < count[0]; i++)
        {
            found = vec.at(i).find("Rectangle");
            str = vec.at(i);
            if (found != std::string::npos)
            {
                try
                {
                    getNum(str, _match, pattern);
                    //s = new Rectangle(value[0], value[1]);
                    shapes.push_back(new Rectangle("0", value[0], value[1]));
                }
                catch (std::string e)
                {
                    continue;
                }
            }
            else if (vec.at(i).find("Ellipse") != std::string::npos)
            {
                try
                {
                    getNum(str, _match, pattern);
                    shapes.push_back(new Ellipse("0", value[0], value[1]));
                }
                catch (std::string e)
                {
                    continue;
                }
            }
            else if (vec.at(i).find("Triangle") != std::string::npos)
            {
                try
                {
                    getNum(str, _match, pattern);
                    triangleVector.push_back(new TwoDimensionalCoordinate(value[0], value[1]));
                    triangleVector.push_back(new TwoDimensionalCoordinate(value[2], value[3]));
                    triangleVector.push_back(new TwoDimensionalCoordinate(value[4], value[5]));
                    //s = new Triangle(triangleVector);
                    shapes.push_back(new Triangle("0", triangleVector));
                }
                catch (std::string e)
                {
                    continue;
                }
            }
            cout << shapes[final_amount]->area() << endl;
            final_amount++;
        }
        if (shapes.size() <= 0)
        {
            throw string("invalid input");
        }
    }

    std::string
    showResult()
    {
        string outcome = "";
        if (type[1] == "inc")
        {
            quickSort(shapes.begin(), shapes.end(), AscendingCompare(type[0]));
        }
        else if (type[1] == "dec")
        {
            quickSort(shapes.begin(), shapes.end(), DescendingCompare(type[0]));
        }

        if (type[0] == "area")
        {
            for (int i = 0; i < shapes.size(); i++)
            {
                outcome += DTS(shapes[i]->area(), 3);
                cout << "shapes[" << i << "]->area=" << shapes[i]->area() << endl;
                if (i < shapes.size() - 1)
                    outcome += "\n";
            }
        }
        else if (type[0] == "perimeter")
        {
            for (int i = 0; i < shapes.size(); i++)
            {
                outcome += DTS(shapes[i]->perimeter(), 3);
                cout << "shapes[" << i << "]->perimeter=" << shapes[i]->perimeter() << endl;
                if (i < shapes.size() - 1)
                    outcome += "\n";
            }
        }
        return outcome;
    }
    void getNum(string _str, smatch sm, regex r)
    {
        int i = 0;
        while (regex_search(_str, _match, pattern))
        {
            ss.str("");
            ss.clear();
            cout << "\nMatched string is " << _match.str(0) << endl
                 << "and it is found at position "
                 << _match.position(0) << endl;
            ss << _match.str(0);
            ss >> value[i];

            cout << value[i] << endl;
            i++;

            // suffix to find the rest of the string.
            _str = _match.suffix().str();
        }
    }
};
