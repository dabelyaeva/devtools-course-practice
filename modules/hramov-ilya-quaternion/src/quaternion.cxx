// Copyright 2016 Hramov Ilya

#include "include/quaternion.h"

// Constructor
Quaternion::Quaternion(
    const double &x,
    const double &y,
    const double &z,
    const double &w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

// Setters getters
void Quaternion::setX(const double &x) {
    this->x = x;
}

void Quaternion::setY(const double &y) {
    this->y = y;
}

void Quaternion::setZ(const double &z) {
    this->z = z;
}

void Quaternion::setW(const double &w) {
    this->w = w;
}

double Quaternion::getX() const {
    return x;
}

double Quaternion::getY() const {
    return y;
}

double Quaternion::getZ() const {
    return z;
}

double Quaternion::getW() const {
    return w;
}

// Operators
Quaternion Quaternion::operator+(const Quaternion &operand) const {
    return Quaternion(
        x + operand.x,
        y + operand.y,
        z + operand.z,
        w + operand.w);
}

Quaternion Quaternion::operator-(const Quaternion &operand) const {
    return Quaternion(
        x - operand.x,
        y - operand.y,
        z - operand.z,
        w - operand.w);
}

Quaternion& Quaternion::operator+=(const Quaternion &operand) {
    x += operand.x;
    y += operand.y;
    z += operand.z;
    w += operand.w;
    return *this;
}

Quaternion& Quaternion::operator-=(const Quaternion &operand) {
    x -= operand.x;
    y -= operand.y;
    z -= operand.z;
    w -= operand.w;
    return *this;
}

Quaternion Quaternion::operator*(const Quaternion &operand) const {
    Quaternion tmp;
    tmp.x = w * operand.x + operand.w * x + y * operand.z - operand.y * z;
    tmp.y = w * operand.y + operand.w * y - x * operand.z + operand.x * z;
    tmp.z = w * operand.z + operand.w * z + x * operand.y - operand.x * y;
    tmp.w = w * operand.w - x * operand.x - y * operand.y - z * operand.z;
    return tmp;
}

Quaternion& Quaternion::operator*=(const Quaternion &operand) {
    *this = (*this) * operand;
    return *this;
}

Quaternion Quaternion::operator!() const {
    return this->conjugated();
}

Quaternion operator*(const double &scalar, const Quaternion &operand) {
    return Quaternion(
        scalar * operand.x,
        scalar * operand.y,
        scalar * operand.z,
        scalar * operand.w);
}

Quaternion Quaternion::operator~() const {
    return this->inversed();
}

bool Quaternion::operator==(const Quaternion &operand) const {
    return isZero(*this - operand);
}

bool Quaternion::operator!=(const Quaternion &operand) const {
    return !(*this == operand);
}

// Math actions
double Quaternion::magnitude() const {
    return sqrt(x*x + y*y + z*z + w*w);
}

double Quaternion::qmagnitude() const {
    return (x*x + y*y + z*z + w*w);
}

Quaternion Quaternion::normalized() const {
    Quaternion tmp;
    double one = 1.0 / sqrt(x*x + y*y + z*z + w*w);
    tmp.x = x * one;
    tmp.y = y * one;
    tmp.z = z * one;
    tmp.w = w * one;
    return tmp;
}

Quaternion Quaternion::conjugated() const {
    return Quaternion(-x, -y, -z, w);
}

Quaternion Quaternion::inversed() const {
    Quaternion tmp;
    double one = 1.0 / (x*x + y*y + z*z + w*w);
    tmp.x = -(x * one);
    tmp.y = -(y * one);
    tmp.z = -(z * one);
    tmp.w = w * one;
    return tmp;
}

// Other
bool Quaternion::isZero(const Quaternion &operand) {
    return operand.x < epsilon && operand.x > -epsilon &&
        operand.y < epsilon && operand.y > -epsilon &&
        operand.z < epsilon && operand.z > -epsilon &&
        operand.w < epsilon && operand.w > -epsilon;
}
