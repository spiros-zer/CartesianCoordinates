// Spyridon Zervos ©


#include <sstream>
#include <cmath>

#include "CartesianCoordinates2D.h"

#include <iostream>

CartesianCoordinates2D::CartesianCoordinates2D(double InX, double InY)
{
    X = InX;
    Y = InY;
    SetModulus(sqrt(pow(X,2) + pow(Y, 2)));
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

std::string CartesianCoordinates2D::ToString() const
{
    std::ostringstream OutputStringStream;
    OutputStringStream << "(" << X << ", " << Y << ")";
    return OutputStringStream.str();
}

char* CartesianCoordinates2D::ToString(int Precision, int& InSize) const
{
    int SizeX{0}, SizeY{0};
    char* XToCString = DoubleToCstring(X, Precision, SizeX);
    char* YToCString = DoubleToCstring(Y, Precision, SizeY);

    const int TotalSize = SizeX + SizeY - 1 + /*parenthesis*/ 2 + /*comma*/ 1;
    char* Result = new char[TotalSize];

    Result[0] = '(';
    Result[TotalSize - 2] = ')';

    int j = 1;
    for (; j < SizeX; ++j)
    {
        Result[j] = XToCString[j];
    }

    for (int i = 1; i < SizeY - 1; ++i)
    {
        Result[j++] = YToCString[i];
    }
    
    InSize = TotalSize;
    return XToCString;
}

char* CartesianCoordinates2D::DoubleToCstring(double InNum, int Precision, int& Size) const
{
    const bool bIsNegative = InNum > 1 ? 0 : 1;
    int IntDigits{bIsNegative}, DecDigits{0}, Digits{0}, Part{};

    /** DIGITS CALCULATION */
    Part = /*IntPart*/ static_cast<int>(InNum);
    while (Part)
    {
        Part /= 10;
        ++IntDigits;
    }
    
    Part = /*DecPart*/ static_cast<int>((InNum - static_cast<int>(InNum)) * static_cast<int>(pow(10, Precision)));
    while (Part)
    {
        Part /= 10;
        ++DecDigits;
    }

    Digits += /*'-'*/ (InNum < 0 ? 1 : 0) + IntDigits + /*'.'*/ 1 + DecDigits + /*'\0'*/ 1;
    Size = Digits;

    /** DIGITS EMPLACEMENT */
    char* Result = new char[Digits];

    if (InNum < 0)
    {
        Result[0] = '-';
    }

    Part = static_cast<int>(abs(InNum));
    for (int i = IntDigits; i > 0; --i)
    {
        const int Digit = (Part - Part % static_cast<int>(pow(10, i - 1))) / static_cast<int>(pow(10, i - 1));
        Part = Part % static_cast<int>(pow(10, i - 1));
        Result[IntDigits - i] = '0' + Digit;
    }

    Result[IntDigits + (bIsNegative ? 1 : 0)] = '.';
    
    Part = static_cast<int>(abs((InNum - static_cast<int>(InNum))) * pow(10, Precision));
    for (int i = DecDigits; i > 0; --i)
    {
        const int Digit = (Part - Part % static_cast<int>(pow(10, i - 1))) / static_cast<int>(pow(10, i - 1));
        Part = Part % static_cast<int>(pow(10, i - 1));
        Result[IntDigits + 1 + (bIsNegative ? 1 : 0) + DecDigits - i] = '0' + Digit;
    }

    /** NULL CHARACTER */
    Result[Digits - 1] = '\0';
    
    return Result;
}
