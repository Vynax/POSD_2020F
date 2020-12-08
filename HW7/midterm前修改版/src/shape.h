#ifndef SHAPE_H
#define SHAPE_H

#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
class Visitor;
//#include "null_iterator.h"
//#include "iterator.h"
class Iterator;
//using namespace std;
class Shape
{
protected:
    std::string _id, _color;
    Iterator *null_itr;

public:
    //std::vector<Shape *> *_shapes;
    Shape(std::string id);                        // interface for default color "white".
    Shape(std::string id, std::string color);     // interface for color input by user.
    std::string id() const { return _id; };       // return id of shape.
    std::string color() const { return _color; }; // return color of shape.

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
    virtual std::string type() const = 0;

    virtual void addShape(Shape *shape);               // throw std::string "Only compound shape can add shape!"
    virtual void deleteShapeById(std::string id);      // throw std::string "Only compound shape can delete shape!"
    virtual Shape *getShapeById(std::string id) const; // throw std::string "Only compound shape can get shape!"
    virtual Iterator *createIterator() const;
    virtual void accept(Visitor *visitor) = 0;
    virtual ~Shape();
};

//將x取到小數點後y位數，回傳double值 RTD:roundtodigit
double RTD(double x, int y);
//將x取到小數點後y位數，回傳string DTS:doubletostring
std::string DTS(double x, int y);
double STD(std::string s);

#endif