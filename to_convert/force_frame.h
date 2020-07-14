#ifndef IMPULSE_H
#define IMPULSE_H
#include "vector.h"
#include <vector>
class Impulse
{
  public:
    static std::vector<Impulse> resolve(std::vector<Impulse> in);
    double start;
    double end;
    Vector force;
};
#endif
