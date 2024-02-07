// Spyridon Zervos ©


#pragma once

#include <string>

struct CartesianCoordinates2D
{
    double X;
    
    double Y;

    /** @brief Magnitude of (x, y) or its distance from origin (0, 0) */  
    double modulus;

    CartesianCoordinates2D(double InX, double InY);
    CartesianCoordinates2D();

    [[nodiscard]] double GetX() const {return X;}
    void SetX(double InX) {X = InX;}

    [[nodiscard]] double GetY() const {return Y;}
    void SetY(double InY) {Y = InY;}

    [[nodiscard]] double Abs() const {return modulus;}
    [[nodiscard]] double GetModulus() const {return Abs();}
    void SetModulus(double InModulus) {modulus = InModulus;}

    /** Operator Overloading */
    CartesianCoordinates2D operator+(const CartesianCoordinates2D& Point) const;
    CartesianCoordinates2D operator-(const CartesianCoordinates2D& Point) const;

    /** @brief Converts the cartesian coordinates to a std::string. */
    std::string ToString() const;
    char* ToString(int Precision, int& InSize) const;
    char* DoubleToCstring(double InNum, int Precision, int& Size) const;
};
