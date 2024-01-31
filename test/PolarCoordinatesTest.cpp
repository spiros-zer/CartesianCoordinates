// (c) Spyridon Zervos


#include "PolarCoordinates.h"

#include<iostream>

int main(int argc, char* argv[])
{
    PolarCoordinates s(1, 90);
    std::cout << s.ToString() << '\n';
    return 0;
}