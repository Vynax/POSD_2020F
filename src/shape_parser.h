#ifndef SHAPE_PARSER_H
#define SHAPE_PARSER_H

#include "scanner.h"
#include "shape_builder.h"
#include <sstream>
class ShapeParser
{
public:
    ShapeParser(std::string input)
    {
        // initialize a scanner for handling input.
        scanner = Scanner(input);
        // initialize a shape builder for handling building shape.

        word.push_back("Ellipse");
        word.push_back("Rectangle");
        word.push_back("Triangle");
        word.push_back("CompoundShape");

        ell_rule.push_back("(");
        ell_rule.push_back("num");
        ell_rule.push_back(",");
        ell_rule.push_back("num");
        ell_rule.push_back(")");

        rec_rule.push_back("(");
        rec_rule.push_back("num");
        rec_rule.push_back(",");
        rec_rule.push_back("num");
        rec_rule.push_back(")");

        tri_rule.push_back("(");
        tri_rule.push_back("num");
        tri_rule.push_back(",");
        tri_rule.push_back("num");
        tri_rule.push_back(",");
        tri_rule.push_back("num");
        tri_rule.push_back(",");
        tri_rule.push_back("num");
        tri_rule.push_back(",");
        tri_rule.push_back("num");
        tri_rule.push_back(",");
        tri_rule.push_back("num");
        tri_rule.push_back(")");
    }

    void parser()
    {
        // using Scanner::nextToken() to get all information to determine what to build,
        // and provide the argument the shape needed.
        // use functions in ShapeBuilder to build out the shape.
        // the shape with invalid argument should be ignored (see example bellow).
        string temp;
        string temp1;
        //first = scanner.nextToken();
        try
        {
            while (scanner.input_size() >= 0)
            {
                //cout << scanner.input_size() << endl;
                temp = scanner.nextToken();
                if (!scanner.str_in_array(temp, word))
                    continue;
                if (temp == "Ellipse")
                {
                    if (check_rule(ell_rule))
                        sb.buildEllipse(array[0], array[1]);
                }
                else if (temp == "Rectangle")
                {
                    if (check_rule(rec_rule))
                        sb.buildRectangle(array[0], array[1]);
                }
                else if (temp == "Triangle")
                {
                    if (check_rule(tri_rule))
                        sb.buildTriangle(array[0], array[1], array[2], array[3], array[4], array[5]);
                }
                else if (temp == "CompoundShape")
                {
                    temp1 = scanner.nextToken();
                    if (temp1 == "{")
                    {
                        sb.buildCompoundShapeBegin();
                        temp1 = scanner.nextToken();
                        while (temp1 != "}" && scanner.input_size() >= 0)
                        {
                            parser();
                        }
                        sb.buildCompoundShapeEnd();
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
        int num_index = 0; //第幾個數字
        std::string temp;
        for (int i = 0; i < rule.size(); i++)
        {
            temp = scanner.nextToken();
            if (rule.at(i) == "num")
            {
                if (scanner.isNum(temp))
                {
                    array[num_index] = STD(temp);
                    num_index++;
                }
                else
                    return false;
            }
            else if (temp != rule.at(i))
                return false;
        }
        return true;
    }

    double STD(std::string s)
    {
        double num;
        stringstream ss;
        ss << s;
        ss >> num;
        return num;
    }
    std::deque<Shape *> getResult()
    {
        // return result.
        return sb.getResult();
    }

private:
    Scanner scanner;
    ShapeBuilder sb;
    double array[6];
    std::vector<string> word;
    std::vector<string> ell_rule; //ellipse_rule
    std::vector<string> rec_rule; //rectangle_rule
    std::vector<string> tri_rule; //triangle_rule
    std::vector<string> cs_rule;  //compoundshape_rule
};

#endif