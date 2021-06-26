#include "linmath.hpp"


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
Vector<T>& Vector<T>::norm() {
    *this = *this / this->length();

    return *this;
}

template <typename T>
T Vector<T>::dot(Vector<T>& vector) const {
    return x * vector.x + y * vector.y + z * vector.z;
}

template <typename T>
Vector<T>& Vector<T>::clamp(Vector<T>& vector, T min, T max) {
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
