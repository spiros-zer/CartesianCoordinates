// Spyridon Zervos ©


#pragma once

#include <string>

struct CartesianCoordinates2D
{
    double X, Y;

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

    /** OPERATOR OVERLOADING */
    CartesianCoordinates2D operator+(const CartesianCoordinates2D& Point) const;
    CartesianCoordinates2D operator-(const CartesianCoordinates2D& Point) const;

    /** STRING OPERATIONS */
    /** @brief Converts the cartesian coordinates to a std::string. */
    std::string ToString() const;

    /** @brief Converts double to char* */
    char* DoubleToCstring(double InNum, int& Size, int Precision = 2) const;

    /** @brief Converts cartesian coordinate to char* */
    char* ToString(int& InSize, int Precision = 2) const;
};
