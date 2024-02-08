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

char* CartesianCoordinates2D::ToString(int& InSize, int Precision) const
{
    int SizeX{0}, SizeY{0};
    
    char* XToCString = DoubleToCstring(X, SizeX, Precision);
    char* YToCString = DoubleToCstring(Y, SizeY, Precision);

    const int TotalSize = SizeX + SizeY - 1 + /*parenthesis*/ 2 + /*comma*/ 1;
    char* Result = new char[TotalSize];

    /** STRUCTURING RESULT */
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

char* CartesianCoordinates2D::DoubleToCstring(double InNum, int& Size, int Precision) const
{
    const bool bIsNegative = InNum >= 0 ? 0 : 1;
    bool bIsIntPartNull{false}, bIsDecPartNull{false};
    int IntDigits{0}, DecDigits{0}, Digits{0};

    /** DIGITS CALCULATION */
    int Part = /*IntPart*/ static_cast<int>(InNum);
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

    if (!IntDigits)
    {
        bIsIntPartNull = true;
        Digits++;
    }

    if (!DecDigits)
    {
        bIsDecPartNull = true;
        Digits++;
    }
    
    Digits += /*'-'*/ (bIsNegative ? 1 : 0) + IntDigits + /*'.'*/ 1 + DecDigits + /*'\0'*/ 1;

    /** DIGITS EMPLACEMENT */
    char* Result = new char[Digits];

    if (bIsNegative)
        Result[0] = '-';

    if (bIsIntPartNull)
        Result[(bIsNegative ? 1 : 0)] = '0';
    
    if (bIsDecPartNull)
        Result[(bIsIntPartNull ? 1 : IntDigits) + (bIsNegative ? 1 : 0) + 1] = '0';
    
    Part = static_cast<int>(abs(InNum));
    for (int i = IntDigits; i > 0; i--)
    {
        const int Digit = (Part - Part % static_cast<int>(pow(10, i - 1))) / static_cast<int>(pow(10, i - 1));
        Part = Part % static_cast<int>(pow(10, i - 1));
        Result[IntDigits + (bIsNegative ? 1 : 0) - i] = '0' + Digit;
    }

    Result[(bIsIntPartNull ? 1 : IntDigits) + (bIsNegative ? 1 : 0)] = '.';
    
    Part = static_cast<int>(abs((InNum - static_cast<int>(InNum))) * pow(10, Precision));
    for (int i = DecDigits; i > 0; i--)
    {
        const int Digit = (Part - Part % static_cast<int>(pow(10, i - 1))) / static_cast<int>(pow(10, i - 1));
        Part = Part % static_cast<int>(pow(10, i - 1));
        Result[(bIsIntPartNull ? 1 : IntDigits) + 1 + (bIsNegative ? 1 : 0) + DecDigits - i] = '0' + Digit;
    }

    /** NULL CHARACTER */
    Result[Digits - 1] = '\0';

    Size = Digits;
    return Result;
}
