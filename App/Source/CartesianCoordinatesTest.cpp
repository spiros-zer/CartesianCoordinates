// (c) Spyridon Zervos


#include<iostream>

#include "Core\CartesianCoordinates2D.h"

int main(int argc, char* argv[])
{
    const CartesianCoordinates2D Point(2, 0);
    std::cout << Point.ToString() << "\n";
    return 0;
}
