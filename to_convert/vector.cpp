#include "vector.h"

inline Cartesian convertVector(Polar p)
{
  assert(p.magnitude > 0);
  return {p.magnitude * cos(p.direction), p.magnitude * sin(p.direction)};
}
inline Polar convertVector(Cartesian c)
{
  return {std::hypot(c.x, c.y), atan2(c.y, c.x)};
}
Vector::Vector() { }
Vector::Vector(Polar p)
{
  this -> point = convertVector(p);
}
Vector::Vector(Cartesian c)
{
  this -> point = c;
}
Vector Vector::operator *(double scalar)
{
  return Cartesian{scalar * point.x, scalar * point.y};
}
void Vector::operator *=(double scalar)
{
  point = {scalar * point.x, scalar * point.y};
}
Vector Vector::operator /(double scalar)
{
  return Cartesian{point.x / scalar, point.y / scalar};
}
void Vector::operator /=(double scalar)
{
  point = {point.x / scalar, point.y / scalar};
}
Vector Vector::operator +(const Vector& other)
{
  return Cartesian{point.x + other.point.x, point.y + other.point.y};
}
void Vector::operator +=(const Vector& other)
{
  point = {point.x + other.point.x, point.y + other.point.y};
}
double Vector::operator [](size_t index)
{
  assert(index == 0 || index == 1);
  return index ? point.y : point.x;
}
Vector Vector::operator -()
{
   return Cartesian{-point.x, -point.y};
}
Vector Vector::operator -(const Vector& other)
{
  return Cartesian{point.x - other.point.x, point.y - other.point.y};
}
void Vector::operator -=(const Vector& other)
{
  this -> point = {point.x - other.point.x, point.y - other.point.y};
}
bool Vector::operator ==(const Vector& other)
{
  return (point.x == other.point.x) && (point.y == other.point.y);
}
Vector::operator bool() const
{
  return point.x || point.y; 
}
Cartesian Vector::getCartesian()
{
  return point;
}
Polar Vector::getPolar()
{
  return convertVector(point);
}

const Vector Vector::ones = Cartesian{1, 1};
const Vector Vector::i = Cartesian{1, 0};
const Vector Vector::j = Cartesian{0, 1};
