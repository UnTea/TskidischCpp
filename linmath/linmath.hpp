#pragma once


#include <cmath>
#include <iostream>
#include <algorithm>


const float EPSILON = 1e-5;
const float PI = 3.14159265358979323846;


template <typename T> class Vector;
template <typename T> std::ostream& operator<< (std::ostream&, const Vector<T>&);


template <typename T>
class Vector {
public:
    T x, y, z;

    Vector() = default;

    explicit Vector(T scalar)
    : x(scalar)
    , y(scalar)
    , z(scalar)
    {}

    explicit Vector(T x, T y, T z)
    : x(x)
    , y(y)
    , z(z)
    {}

    ~Vector() = default;

    Vector<T>& operator + (T);
    Vector<T>& operator +=(T);
    Vector<T>& operator + (const Vector<T>&);
    Vector<T>& operator +=(const Vector<T>&);
    Vector<T>& operator - ();
    Vector<T>& operator - (T);
    Vector<T>& operator -=(T);
    Vector<T>& operator - (const Vector<T>&);
    Vector<T>& operator -=(const Vector<T>&);
    Vector<T>& operator * (T);
    Vector<T>& operator *=(T);
    Vector<T>& operator * (const Vector<T>&);
    Vector<T>& operator *=(const Vector<T>&);
    Vector<T>& operator / (T);
    Vector<T>& operator /=(T);
    Vector<T>& operator / (const Vector<T>&);
    Vector<T>& operator /=(const Vector<T>&);

    friend std::ostream& operator<< <T>(std::ostream&, const Vector<T>&);
    [[nodiscard]] T length() const;
    Vector<T>& normal();
    T dot(Vector<T>&) const;
};

template <typename T>
T clamp(T, T, T);

template <typename T>
Vector<T>& clamp(Vector<T>&, T, T);

template <typename T>
T power(T, T);

template <typename T>
Vector<T>& power(Vector<T>&, T);

template <typename T>
Vector<T>& Vector<T>::operator +(T scalar) {
    x += scalar;
    y += scalar;
    z += scalar;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator +=(T scalar) {
    *this = *this + scalar;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator +(const Vector<T>& vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator +=(const Vector<T>& vector) {
    *this = *this + vector;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator -() {
    x = -x;
    y = -y;
    z = -z;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator -(T scalar) {
    x -= scalar;
    y -= scalar;
    z -= scalar;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator -=(T scalar) {
    *this = *this - scalar;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator -(const Vector<T>& vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator -=(const Vector<T>& vector) {
    *this = *this - vector;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator *(T scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator *=(T scalar) {
    *this = *this * scalar;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator *(const Vector<T>& vector){
    x *= vector.x;
    y *= vector.y;
    z *= vector.z;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator *=(const Vector<T>& vector) {
    *this = *this * vector;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator /(T scalar){
    float reciprocal = scalar / this->length();

    return *this * reciprocal;
}

template <typename T>
Vector<T>& Vector<T>::operator /=(T scalar) {
    *this = *this / scalar;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator /(const Vector<T>& vector) {
    x /= vector.x;
    y /= vector.y;
    z /= vector.z;

    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator /=(const Vector<T>& vector) {
    *this = *this / vector;

    return *this;
}

template <typename T>
std::ostream& operator <<(std::ostream& ostream, const Vector<T>& vector) {
    ostream << vector.x << '/' << vector.y << '/' << vector.z;

    return ostream;
}

template <typename T>
T Vector<T>::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

template <typename T>
Vector<T>& Vector<T>::normal() {
    *this = *this / this->length();

    return *this;
}

template <typename T>
T Vector<T>::dot(Vector<T>& vector) const {
    return x * vector.x + y * vector.y + z * vector.z;
}

template <typename T>
Vector<T>& clamp(Vector<T>& vector, T min, T max) {
    vector.x = std::clamp(vector.x, min, max);
    vector.y = std::clamp(vector.y, min, max);
    vector.z = std::clamp(vector.z, min, max);

    return vector;
}

template <typename T>
T power(T scalar_1, T scalar_2) {
    return std::pow(scalar_1, scalar_2);
}

template <typename T>
Vector<T>& power(Vector<T>& vector, T scalar) {
    vector.x = power(vector.x, scalar);
    vector.y = power(vector.y, scalar);
    vector.z = power(vector.z, scalar);

    return vector;
}
