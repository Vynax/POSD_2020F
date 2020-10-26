#include "shape.h"

void Shape::addShape(Shape *shape)
{
    throw std::string("Only compound shape can add shape!");
}

void Shape::deleteShapeById(std::string id)
{
    throw std::string("Only compound shape can delete shape!");
}

Shape *Shape::getShapeById(std::string id)
{
    throw std::string("Only compound shape can get shape!");
}

// std::string Shape::id()
// {
//     return _id;
// }

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
    stringstream ss;
    ss.str(""); //clear
    ss.clear();
    ss << fixed << setprecision(y) << x;
    ss >> x;
    return x;
}
//將x取到小數點後y位數，回傳string DTS:doubletostring
std::string DTS(double x, int y)
{
    stringstream ss;
    ss.str(""); //clear
    //oss.precision(y);
    ss << fixed << setprecision(y) << x;
    //ss >> x;
    //printf(x);
    return ss.str();
}