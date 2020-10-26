#ifndef TRITEST_H
#define TRITEST_H

#include "two_dimensional_coordinate.h"

class Tritest
{
private:
    std::vector<TwoDimensionalCoordinate *> _vectors;
    double *length;

public:
    Tritest(vector<TwoDimensionalCoordinate *> vectors)
    {
        _vectors = vectors;
        length = new double[_vectors.size()];
    }

    //檢查三角形是否成立
    bool triangletest()
    {
        int i;
        int size = _vectors.size();
        for (i = 0; i < size; i++)
        {
            length[i] = callength(_vectors[i], _vectors[(i + 1) % size]); //用取餘數來防止超出vector範圍
        }
        for (i = 0; i < size; i++)
        {
            if (length[i] == 0) //任一邊長為零就不可能是三角形
                return false;
            else if (length[i] + length[(i + 1) % size] <= length[(i + 2) % size])
                return false;
        }

        return true;
    }

    //計算兩點之間長度 calculate length
    double callength(TwoDimensionalCoordinate *dot1, TwoDimensionalCoordinate *dot2)
    {
        return sqrt(pow(dot1->getX() - dot2->getX(), 2) + pow(dot1->getY() - dot2->getY(), 2));
    }
};

#endif