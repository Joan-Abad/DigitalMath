#pragma once
#include <cmath>
#include <iostream>
#include "DigitalMath.h"

template <typename T>
struct DIGITALMATH_API Vector3
{    
    T x, y, z;

    //Constructors
    Vector3() : x(0), y(0), z(0){}
    Vector3(T x, T y, T z) : x(x), y(y), z(z){}

    //Arithmetic operators
    Vector3 operator+(const Vector3 other) const { return Vector3(x + other.x, y + other.y, z + other.z); }
    Vector3 operator-(const Vector3 other) const { return Vector3(x - other.x, y - other.y, z - other.z); }
    Vector3 operator*(const Vector3 other) const { return Vector3(x * other.x, y * other.y, z * other.z); }

    // Dot product between two vectors
    T Dot(const Vector3& other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    // Cross product between two vectors
    Vector3 Cross(const Vector3& other) const {
        return Vector3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Gets the length of the vector
    T Length() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Normalize
    Vector3& Normalize() const {
        T length = Length();
        x /= length;
        y /= length;
        z /= length; 
        return this;
    }

    // Returns a copy of the normal
    Vector3 SafeNormal() const {
        T length = Length();
        return (length == 0) ? Vector3() : Vector3(x / length, y / length, z / length);
    }

    //Returns a Vector3(0, 0, 0) 
    Vector3 Zero() const
    {
        return Vector3(0, 0, 0); 
    }
    
    //Returns a Vector3(1, 1, 1) 
    Vector3 One() const
    {
        return Vector3(1, 1, 1);  
    }
};
