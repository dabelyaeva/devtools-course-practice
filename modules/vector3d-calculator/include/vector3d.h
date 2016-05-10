// Copyright 2016 Rumyantsev Alexander

#ifndef MODULES_VECTOR3D_CALCULATOR_INCLUDE_VECTOR3D_H_
#define MODULES_VECTOR3D_CALCULATOR_INCLUDE_VECTOR3D_H_

#include <stdexcept>

class DivisionByZero : public std::runtime_error {
 public:
  DivisionByZero() : std::runtime_error("Can't divide by zero") {}
};

class NullVectorNormalizing : public std::runtime_error {
 public:
  NullVectorNormalizing() : std::runtime_error("Can't normalize null vector") {}
};

class Vector3D {
 public:
  Vector3D();
  Vector3D(const double x, const double y, const double z);
  Vector3D(const Vector3D& v);

  Vector3D& operator=(const Vector3D& v);

  double getX() const;
  double getY() const;
  double getZ() const;

  void setX(const double x);
  void setY(const double y);
  void setZ(const double z);

  Vector3D operator+(const Vector3D& v) const;
  Vector3D operator-(const Vector3D& v) const;
  Vector3D operator-() const;

  Vector3D operator*(const double k) const;
  friend Vector3D operator*(const double k, const Vector3D& v);
  Vector3D operator/(const double k) const;

  bool operator==(const Vector3D& v) const;
  bool operator!=(const Vector3D& v) const;

  double magnitude() const;
  void normalize();
  double dot(const Vector3D& v) const;
  Vector3D cross(const Vector3D& v) const;

 private:
  double x_;
  double y_;
  double z_;

  bool isNullVector() const;
};

#endif  // MODULES_VECTOR3D_CALCULATOR_INCLUDE_VECTOR3D_H_
