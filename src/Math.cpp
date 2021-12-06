#include <cmath>
#include <Math.h>

bool
math::close(double a, double b, double epsilon)
{
    return std::fabs(a - b) < epsilon;
}

double
math::adjacent(double tiltAngleDeg, double hypotenuse)
{
    return std::cos(degToRad(tiltAngleDeg)) * hypotenuse;
}

double
math::opposite(double tiltAngleDeg, double hypotenuse)
{
    return std::sin(degToRad(tiltAngleDeg)) * hypotenuse;
}

double
math::tiltAngleDeg(double opposite, double adjacent)
{
    return radToDeg(std::atan2(opposite, adjacent));
}

double
math::hypotenuse(double opposite, double adjacent)
{
    return std::sqrt((opposite * opposite) + (adjacent * adjacent));
}

double
math::hypotenuse(double tiltAngleDeg, Opposite &opposite)
{
    return opposite.lenght / std::sin(degToRad(tiltAngleDeg));
}

double
math::hypotenuse(double tiltAngleDeg, Adjacent &adjacent)
{
    return adjacent.lenght / std::cos(degToRad(tiltAngleDeg));
}