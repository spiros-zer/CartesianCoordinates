// Spyridon Zervos ©


#pragma once

#include <string>

struct CartesianCoordinates2D
{
    double x;
    
    double y;

    /** @brief Magnitude of (x, y) or its distance from origin (0, 0) */  
    double modulus;

    CartesianCoordinates2D(double InX, double InY);
    CartesianCoordinates2D();

    double GetX() const {return x;}
    void SetX(double InX) {x = InX;}

    double GetY() const {return y;}
    void SetY(double InY) {y = InY;}

    double Abs() const {return modulus;}
    void SetModulus(double InModulus) {modulus = InModulus;}

    /** Operator Overloading */
    CartesianCoordinates2D operator+(const CartesianCoordinates2D& Point) const;

    CartesianCoordinates2D operator-(const CartesianCoordinates2D& Point) const;

    /** @brief Converts the cartesian coordinates to a std::string. */
    std::string ToString() const;
};
