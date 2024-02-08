// Spyridon Zervos ©


#pragma once

#include <string>

struct CartesianCoordinates2D
{
    /** @brief (x, y) fields. */
    double X{}, Y{};
    
    /** @brief Array containing the coordinate pair. */
    char* Cstring;
    
    /** @brief Size of the array. */
    int Size{};

    /** @brief Magnitude of (x, y) or its distance from origin (0, 0). */  
    double modulus{};

    /**** CONSTRUCTORS/DESTRUCTORS */
    CartesianCoordinates2D(double InX, double InY);
    CartesianCoordinates2D();

    /**** GETTERS/SETTERS */
    [[nodiscard]] double GetX() const {return X;}
    void SetX(double InX) {X = InX;}

    [[nodiscard]] double GetY() const {return Y;}
    void SetY(double InY) {Y = InY;}

    [[nodiscard]] double Abs() const {return modulus;}
    [[nodiscard]] double GetModulus() const {return Abs();}
    void SetModulus(double InModulus) {modulus = InModulus;}

    [[nodiscard]] int GetCstringSize() const {return Size;}
    void SetSize(int InSize) {Size = InSize;}
    
    [[nodiscard]] char* GetCstring() const {return Cstring;}
    void SetCstring(char* InCstring) {Cstring = InCstring;}

    /**** OPERATOR OVERLOADING */
    CartesianCoordinates2D operator+(const CartesianCoordinates2D& Point) const;
    CartesianCoordinates2D operator-(const CartesianCoordinates2D& Point) const;
    CartesianCoordinates2D operator*(double Num) const;

    /**** STRING OPERATIONS */
    /** @brief Converts the cartesian coordinates to a std::string. */
    std::string ToString() const;

    /** @brief Converts double to char*. */
    char* DoubleToCstring(double InNum, int& Size, int Precision = 2) const;

    /** @brief Converts cartesian coordinate to char*. */
    char* ToString(int& InSize, int Precision = 2) const;

    /** @brief Prints the Cstring in the iostream with the NULL char. */
    void Print() const;
};
