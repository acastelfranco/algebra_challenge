#include <cmath>
#include <Math.h>

bool
math::close(double a, double b, double epsilon)
{
    return std::fabs(a - b) < epsilon;
}

double
math::adjacent(double tiltdeg, double hypotenuse)
{
    return 0.0;
}

double
math::opposite(double tiltdeg, double hypotenuse)
{
    return 0.0;
}