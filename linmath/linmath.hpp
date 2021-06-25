#pragma once


#include <cmath>
#include <iostream>


const float EPSILON = 1e-5;
const float PI = 3.14159265358979323846;


class Vector {
public:
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
    Vector& operator ^ (float);
    Vector& operator ^=(float);

    friend std::ostream& operator <<(std::ostream&, const Vector&);

    [[nodiscard]] float length() const;
    Vector& norm();
    float dot(Vector&) const;
    [[nodiscard]] Vector clamp(float, float) const;
    static float radians(float);
    static Vector splat(float);

    explicit Vector(float x = 1, float y = 1, float z = 1)
    : x(x), y(y), z(z)
    {}

    ~Vector() = default;

private:
    float x, y, z;
};
