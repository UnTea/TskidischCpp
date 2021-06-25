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

Vector& Vector::operator +(const Vector &vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;

    return *this;
}

Vector& Vector::operator +=(const Vector& rhs) {
    *this = *this + rhs;

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

Vector& Vector::operator -=(const Vector& rhs) {
    *this = *this - rhs;

    return *this;
}

Vector& Vector::operator *(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

Vector& Vector::operator *=(float scalar) {
    *this = *this - scalar;

    return *this;
}

Vector& Vector::operator *(const Vector& vector){
    x *= vector.x;
    y *= vector.y;
    z *= vector.z;

    return *this;
}

Vector& Vector::operator *=(const Vector& rhs) {
    *this = *this * rhs;

    return *this;
}

Vector& Vector::operator /(float scalar){
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
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

Vector& Vector::operator /=(const Vector& rhs) {
    *this = *this / rhs;

    return *this;
}

Vector& Vector::operator ^(float scalar) {
    x = powf(x, scalar);
    y = powf(y, scalar);
    z = powf(z, scalar);

    return *this;
}

Vector& Vector::operator ^=(float scalar) {
    *this = *this ^ scalar;

    return *this;
}

std::ostream& operator <<(std::ostream& ostream, const Vector& vector) {
    ostream << vector.x << ' ' << vector.y << ' ' << vector.z;

    return ostream;
}

float Vector::length() const {
    return sqrtf(x * x + y * y + z * z);
}

Vector& Vector::norm() {
    float invert = float(1.0) / this->length();
    *this = *this * invert;

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

float Vector::radians(float degree) {
    return PI * degree / float(180.0);
}

Vector Vector::splat(float scalar) {
    return Vector{
        scalar,
        scalar,
        scalar
    };
}
