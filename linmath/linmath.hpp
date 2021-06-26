#pragma once


#include <cmath>
#include <iostream>


const float EPSILON = 1e-5;
const float PI = 3.14159265358979323846;


class Vector {
public:
    float x, y, z;

    Vector& operator + (float);
    Vector& operator +=(float);
    Vector& operator + (const Vector&);
    Vector& operator +=(const Vector&);
    Vector& operator - ();
    Vector& operator - (float);
    Vector& operator -=(float);
    Vector& operator - (const Vector&);
    Vector& operator -=(const Vector&);
    Vector& operator * (float);
    Vector& operator *=(float);
    Vector& operator * (const Vector&);
    Vector& operator *=(const Vector&);
    Vector& operator / (float);
    Vector& operator /=(float);
    Vector& operator / (const Vector&);
    Vector& operator /=(const Vector&);

    friend std::ostream& operator <<(std::ostream&, const Vector&);
    [[nodiscard]] float length() const;
    Vector& norm();
    float dot(Vector&) const;

    [[nodiscard]] Vector clamp(float, float) const;

    explicit Vector(float scalar)
    : x(scalar), y(scalar), z(scalar)
    { }

    explicit Vector(float x, float y, float z)
    : x(x), y(y), z(z)
    {}

    ~Vector() = default;
};

float power(float, float);
Vector& power(Vector&, float);
