#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <cmath>
#include <vector>
#include <assert.h>

struct Cartesian
{
  double x = 0;
  double y = 0;
};

struct Polar
{
  double magnitude = 0;
  double direction = 0;
};


class Vector
{
  public:
    const static Vector ones;
    const static Vector i;
    const static Vector j;
    Vector();
    Vector(Polar p);
    Vector(Cartesian c);
    Vector operator *(double scalar);
    void operator *=(double scalar);
    Vector operator /(double scalar);
    void operator /=(double scalar);
    Vector operator +(const Vector& other);
    void operator +=(const Vector& other);
    double operator [](size_t index);
    Vector operator -();
    Vector operator -(const Vector& other);
    void operator -=(const Vector& other);
    void operator =(const Vector& other);
    bool operator ==(const Vector& other);
    operator bool() const;
    Cartesian getCartesian();
    Polar getPolar();
  private:
    Cartesian point;
};
#endif
