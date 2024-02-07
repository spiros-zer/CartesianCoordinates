// (c) Spyridon Zervos


#include<iostream>

#include "Core\CartesianCoordinates2D.h"

int main(int argc, char* argv[])
{
    const CartesianCoordinates2D Point(2.39, 12.34);
    int size;
    char* PointStr = Point.ToString(2, size);
    for (int i = 0; i < size; ++i)
    {
        std::cout << PointStr[i];
    }
    std::cout << "main" << std::endl;
    // std::cout << Point.ToString() << "\n";
    return 0;
}
