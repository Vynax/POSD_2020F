#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "two_dimensional_coordinate.h"
#include <math.h>

//class Tritest(vector<TwoDimensionalCoordinate *> aaa){};
class Triangle : public Shape
{
private:
    vector<TwoDimensionalCoordinate *> _vectors;
    //Tritest *tritest;
    double length[3];
    int size;

public:
    Triangle(std::string id, std::vector<TwoDimensionalCoordinate *> vectors) : Shape(id)
    {
        // If the triangle can't be successfully created,
        // handle the exception by throwing string "This is not a triangle!"

        int i;
        _vectors = vectors;
        //tritest = new Tritest(_vectors);
        if (_vectors.size() != 3)
            throw string("This is not a triangle!");
        size = _vectors.size();
        for (i = 0; i < size; i++)
        {
            length[i] = callength(_vectors[i], _vectors[(i + 1) % size]); //用取餘數來防止超出vector範圍
        }
        if (!triangletest()) //如果triangletest失敗就回傳錯誤資訊
            throw string("This is not a triangle!");
        _id = id;
        _color = "white";
    }
    Triangle(std::string id, std::vector<TwoDimensionalCoordinate *> vectors, string color) : Shape(id, color), _vectors(vectors)
    {
        // If the triangle can't be successfully created,
        // handle the exception by throwing string "This is not a triangle!"

        int i;
        _vectors = vectors;
        //tritest = new Tritest(_vectors);
        if (_vectors.size() != 3)
            throw string("This is not a triangle!");
        size = _vectors.size();
        for (i = 0; i < size; i++)
        {
            length[i] = callength(_vectors[i], _vectors[(i + 1) % size]); //用取餘數來防止超出vector範圍
        }
        if (!triangletest()) //如果triangletest失敗就回傳錯誤資訊
            throw string("This is not a triangle!");
        _id = id;
        _color = color;
    }

    double area() const
    {
        // return the area of the Triangle.
        double a = length[0];
        double b = length[1];
        double c = length[2];
        double s = (a + b + c) / 2;

        return sqrt(s * (s - a) * (s - b) * (s - c)); //海龍公式
    }

    double perimeter() const
    {
        // return the perimeter of the Triangle.
        return length[0] + length[1] + length[2];
    }

    std::string info() const
    {
        // return the info of the Triangle.
        // ex. Triangle ([0.000, 0.000], [0.000, -3.141], [-4.000, 0.000])
        int i, j;
        string s;
        s += "Triangle (";
        for (i = 0; i < _vectors.size(); i++)
        {
            s += "[";
            s += DTS(_vectors[i]->getX(), 3);
            s += ", ";
            s += DTS(_vectors[i]->getY(), 3);
            s += "]";
            if (i < _vectors.size() - 1) //三個座標之間有兩個空白
                s += ", ";
        }
        s += ")";
        return s;
    }

    bool triangletest()
    {
        int i;

        for (i = 0; i < size; i++)
        {
            if (length[i] == 0) //任一邊長為零就不可能是三角形
                return false;
            else if (length[i] + length[(i + 1) % size] <= length[(i + 2) % size]) //任兩邊之和必大於第三邊
                return false;
        }

        return true;
    }

    double callength(TwoDimensionalCoordinate *dot1, TwoDimensionalCoordinate *dot2)
    {
        return sqrt(pow(dot1->getX() - dot2->getX(), 2) + pow(dot1->getY() - dot2->getY(), 2)); //兩點距離公式
    }
    /*~Triangle()
    {
        vector<TwoDimensionalCoordinate *>::iterator ptr;
        for (ptr = _vectors.begin(); ptr < _vectors.end(); ptr++)
            delete *ptr;
    }*/
    void addShape(Shape *shape)
    {
        throw std::string("Only compound shape can add shape!");
    }
    void deleteShapeById(std::string id)
    {
        throw std::string("Only compound shape can delete shape!");
    }
    Shape *getShapeById(std::string id)
    {
        throw std::string("Only compound shape can get shape!");
    }
};

#endif