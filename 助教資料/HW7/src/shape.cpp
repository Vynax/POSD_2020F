#include "shape.h"
#include "iterator.h"
#include "null_iterator.h"

Shape::Shape(std::string id) : _id(id), _color("white")
{
    null_itr = new NullIterator();
} // interface for default color "white".
Shape::Shape(std::string id, std::string color) : _id(id), _color(color)
{
    null_itr = new NullIterator();
}

void Shape::addShape(Shape *shape)
{
    throw std::string("Only compound shape can add shape!");
}

void Shape::deleteShapeById(std::string id)
{
    throw std::string("Only compound shape can delete shape!");
}

Shape *Shape::getShapeById(std::string id) const
{
    throw std::string("Only compound shape can get shape!");
}
Iterator *Shape::createIterator() const
{
    return null_itr;
}
Shape::~Shape() {}

//將x取到小數點後y位數，回傳double值 RTD:roundtodigit
double RTD(double x, int y)
{
    /*char xtostr[80];
    string s = "%." + to_string(y) + "f";
    char str[s.length() + 1];
    strcpy(str, s.c_str());
    sprintf(xtostr, str, x);
    //cout << str << endl;
    return atof(xtostr);*/
    std::stringstream ss;
    ss.str(""); //clear
    ss.clear();
    ss << std::fixed << std::setprecision(y) << x;
    ss >> x;
    return x;
}
//將x取到小數點後y位數，回傳string DTS:doubletostring
std::string DTS(double x, int y)
{
    std::stringstream ss;
    ss.str(""); //clear
    //oss.precision(y);
    ss << std::fixed << std::setprecision(y) << x;
    //ss >> x;
    //printf(x);
    return ss.str();
}