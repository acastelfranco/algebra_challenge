#include <cmath>
#include <Math.h>

bool
math::close(double a, double b, double epsilon)
{
    return std::fabs(a - b) < epsilon;
}