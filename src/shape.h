#ifndef SHAPE_H
#define SHAPE_H

#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
};

//將x取到小數點後y位數，回傳double值 RTD:roundtodigit
double RTD(double x, int y)
{
    char str[80];
    sprintf(str, "%.3f", x);
    //cout << str << endl;
    return atof(str);
}
//將x取到小數點後y位數，回傳string DTS:doubletostring
std::string DTS(double x, int y)
{
    ostringstream oss;
    oss.str(""); //clear
    oss.precision(y);
    oss << fixed << x;
    return oss.str();
}

#endif