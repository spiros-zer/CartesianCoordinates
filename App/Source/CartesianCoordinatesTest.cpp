// (c) Spyridon Zervos


#include<iostream>

#include "Core\CartesianCoordinates2D.h"

int main(int argc, char* argv[])
{
    const CartesianCoordinates2D PointA(-0.56, -77.34);
    const CartesianCoordinates2D PointB(2.57, 100);
    CartesianCoordinates2D PointC{};
    int SizeA{}, SizeB{}, SizeC{};

    std::cout << "PointA ";
    const char* PointAStr = PointA.ToString(SizeA);
    for (int i = 0; i < SizeA; ++i)
    {
        std::cout << PointAStr[i];
    }
    std::cout << '\n';
    
    std::cout << "PointB ";
    const char* PointBStr = PointB.ToString(SizeB);
    for (int i = 0; i < SizeB; ++i)
    {
        std::cout << PointBStr[i];
    }
    std::cout << '\n';

    PointC = PointA + PointB;
    std::cout << "PointC ";
    const char* PointCStr = PointC.ToString(SizeC);
    for (int i = 0; i < SizeC; ++i)
    {
        std::cout << PointCStr[i];
    }
    std::cout << '\n';

    return 0;
}
