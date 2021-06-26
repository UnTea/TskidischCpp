#include "linmath.hpp"


Vector& Vector::operator +(float scalar) {
    x += scalar;
    y += scalar;
    z += scalar;

    return *this;
}

Vector& Vector::operator +=(float scalar) {
    *this = *this + scalar;

    return *this;
}

Vector& Vector::operator +(const Vector& vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;

    return *this;
}

Vector& Vector::operator +=(const Vector& vector) {
    *this = *this + vector;

    return *this;
}

Vector& Vector::operator -() {
    x = -x;
    y = -y;
    z = -z;

    return *this;
}

Vector& Vector::operator -(float scalar) {
    x -= scalar;
    y -= scalar;
    z -= scalar;

    return *this;
}

Vector& Vector::operator -=(float scalar) {
    *this = *this - scalar;

    return *this;
}

Vector& Vector::operator -(const Vector& vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;

    return *this;
}

Vector& Vector::operator -=(const Vector& vector) {
    *this = *this - vector;

    return *this;
}

Vector& Vector::operator *(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

Vector& Vector::operator *=(float scalar) {
    *this = *this * scalar;

    return *this;
}

Vector& Vector::operator *(const Vector& vector){
    x *= vector.x;
    y *= vector.y;
    z *= vector.z;

    return *this;
}

Vector& Vector::operator *=(const Vector& vector) {
    *this = *this * vector;

    return *this;
}

Vector& Vector::operator /(float scalar){
    float reciprocal = float(scalar) / this->length();

    return *this * reciprocal;
}

Vector& Vector::operator /=(float scalar) {
    *this = *this / scalar;

    return *this;
}

Vector& Vector::operator /(const Vector& vector) {
    x /= vector.x;
    y /= vector.y;
    z /= vector.z;

    return *this;
}

Vector& Vector::operator /=(const Vector& vector) {
    *this = *this / vector;

    return *this;
}

std::ostream& operator <<(std::ostream& ostream, const Vector& vector) {
    ostream << vector.x << '/' << vector.y << '/' << vector.z;

    return ostream;
}

float Vector::length() const {
    return sqrtf(x * x + y * y + z * z);
}

Vector& Vector::norm() {
    float reciprocal = float(1.0) / this->length();
    *this = *this * reciprocal;

    return *this;
}

float Vector::dot(Vector& vector) const {
    return x * vector.x + y * vector.y + z * vector.z;
}

Vector Vector::clamp(float min, float max) const {
    return Vector(
            std::min(std::max(x, min), max),
            std::min(std::max(y, min), max),
            std::min(std::max(z, min), max)
            );
}

float power(float scalar_1, float scalar_2) {
    return std::pow(scalar_1, scalar_2);
}

Vector& power(Vector& vector, float scalar) {
    vector.x = power(vector.x, scalar);
    vector.y = power(vector.y, scalar);
    vector.z = power(vector.z, scalar);

    return vector;
}
