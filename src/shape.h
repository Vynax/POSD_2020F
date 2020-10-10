#ifndef SHAPE_H
#define SHAPE_H

#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;
class Shape
{
protected:
    string _id, _color;

public:
    Shape(std::string id);                        // interface for default color "white".
    Shape(std::string id, std::string color);     // interface for color input by user.
    std::string id() const;                       // return id of shape.
    std::string color() const;                    // return color of shape.
    virtual void addShape(Shape *shape);          // throw std::string "Only compound shape can add shape!"
    virtual void deleteShapeById(std::string id); // throw std::string "Only compound shape can delete shape!"
    virtual Shape *getShapeById(std::string id);  // throw std::string "Only compound shape can get shape!"

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual string info() const = 0;
};

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

#endif