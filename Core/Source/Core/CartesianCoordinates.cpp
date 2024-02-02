// Spyridon Zervos ©


#include <sstream>
#include <cmath>

#include "CartesianCoordinates.h"

CartesianCoordinates::CartesianCoordinates(double InX, double InY)
{
    x = InX;
    y = InY;
    SetModulus(sqrt(pow(x,2) + pow(y, 2)));
}

CartesianCoordinates::CartesianCoordinates() : CartesianCoordinates(0, 0){}

CartesianCoordinates CartesianCoordinates::operator+(const CartesianCoordinates& Point) const
{
    return {x + Point.GetX(), y + Point.GetY()};
}

CartesianCoordinates CartesianCoordinates::operator-(const CartesianCoordinates& Point) const
{
    return {x - Point.GetX(), y - Point.GetY()};
}

std::string CartesianCoordinates::ToString() const
{
    std::ostringstream OutputStringStream;
    OutputStringStream << "(" << x << ", " << y << ")";
    return OutputStringStream.str();
}
