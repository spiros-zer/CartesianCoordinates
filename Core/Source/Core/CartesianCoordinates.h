// Spyridon Zervos ©


#pragma once

#include <string>

struct CartesianCoordinates
{
    double x;
    
    double y;

    /** @brief Magnitude of (x, y) or its distance from origin (0, 0) */  
    double modulus;

    CartesianCoordinates(double InX, double InY);
    CartesianCoordinates();

    double GetX() const {return x;}
    void SetX(double InX) {x = InX;}

    double GetY() const {return y;}
    void SetY(double InY) {y = InY;}

    double Abs() const {return modulus;}
    void SetModulus(double InModulus) {modulus = InModulus;}

    /** Operator Overloading */
    CartesianCoordinates operator+(const CartesianCoordinates& Point) const;

    CartesianCoordinates operator-(const CartesianCoordinates& Point) const;

    /** @brief Converts the cartesian coordinates to a std::string. */
    std::string ToString() const;
};
