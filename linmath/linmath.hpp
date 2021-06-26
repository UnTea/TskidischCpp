#pragma once


#include <cmath>
#include <iostream>
#include <algorithm>


const float EPSILON = 1e-5;
const float PI = 3.14159265358979323846;


template <typename T>
class Vector {
public:
    T x, y, z;

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

    //FIXME WTF?
    friend std::ostream& operator<< (std::ostream&, const Vector<T>& );
    [[nodiscard]] T length() const;
    Vector<T>& norm();
    T dot(Vector<T>&) const;
    static Vector<T>& clamp(Vector<T>&, T, T) ;

    explicit Vector(T scalar)
    : x(scalar), y(scalar), z(scalar)
    { }

    explicit Vector(T x, T y, T z)
    : x(x), y(y), z(z)
    {}

    ~Vector() = default;
};

template <typename T>
T power(T, T);

template <typename T>
Vector<T>& power(Vector<T>&, T);
