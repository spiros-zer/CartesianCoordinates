// Spyridon Zervos ©


#include <sstream>
#include <cmath>
#include <iostream>

#include "CartesianCoordinates2D.h"

#include "Converters/Double2Cstring.h"

CartesianCoordinates2D::CartesianCoordinates2D(double InX, double InY)
{
    X = InX;
    Y = InY;
    SetModulus(sqrt(pow(X,2) + pow(Y, 2)));
    Cstring = ToString(Size);
}

CartesianCoordinates2D::CartesianCoordinates2D() : CartesianCoordinates2D(0, 0){}

CartesianCoordinates2D CartesianCoordinates2D::operator+(const CartesianCoordinates2D& Point) const
{
    return {X + Point.GetX(), Y + Point.GetY()};
}

CartesianCoordinates2D CartesianCoordinates2D::operator-(const CartesianCoordinates2D& Point) const
{
    return {X - Point.GetX(), Y - Point.GetY()};
}

CartesianCoordinates2D CartesianCoordinates2D::operator*(double Num) const
{
    return {Num * X, Num * Y};
}

std::string CartesianCoordinates2D::ToString() const
{
    std::ostringstream OutputStringStream;
    OutputStringStream << "(" << X << ", " << Y << ")";
    return OutputStringStream.str();
}

char* CartesianCoordinates2D::ToString(int& InSize, int Precision) const
{
    int SizeX{0}, SizeY{0};

    const char* XToCString = Converters::DoubleToCstring(X, SizeX, Precision);
    const char* YToCString = Converters::DoubleToCstring(Y, SizeY, Precision);
    
    const int TotalSize = SizeX + SizeY - 1 + /*parenthesis*/ 2 + /*comma*/ 1;
    char* Result = new char[TotalSize];

    /**** STRUCTURING RESULT */
    Result[0] = '(';
    Result[TotalSize - 2] = ')';
    int j = 1;
    for (; j < SizeX; j++)
    {
        Result[j] = XToCString[j-1];
    }
    Result[j++] = ',';
    for (int i = 0; i < SizeY - 1; i++)
    {
        Result[j++] = YToCString[i];
    }
    Result[TotalSize - 1] = '\0';
    
    InSize = TotalSize;
    return Result;
}

void CartesianCoordinates2D::Print() const
{
    for (int i = 0; i < Size; ++i)
    {
        std::cout << Cstring[i];
    }
}
