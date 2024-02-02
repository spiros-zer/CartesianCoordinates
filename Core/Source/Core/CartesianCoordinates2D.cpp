// Spyridon Zervos ©


#include <sstream>
#include <cmath>

#include "CartesianCoordinates2D.h"

CartesianCoordinates2D::CartesianCoordinates2D(double InX, double InY)
{
    x = InX;
    y = InY;
    SetModulus(sqrt(pow(x,2) + pow(y, 2)));
}

CartesianCoordinates2D::CartesianCoordinates2D() : CartesianCoordinates2D(0, 0){}

CartesianCoordinates2D CartesianCoordinates2D::operator+(const CartesianCoordinates2D& Point) const
{
    return {x + Point.GetX(), y + Point.GetY()};
}

CartesianCoordinates2D CartesianCoordinates2D::operator-(const CartesianCoordinates2D& Point) const
{
    return {x - Point.GetX(), y - Point.GetY()};
}

std::string CartesianCoordinates2D::ToString() const
{
    std::ostringstream OutputStringStream;
    OutputStringStream << "(" << x << ", " << y << ")";
    return OutputStringStream.str();
}
