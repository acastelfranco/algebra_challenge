#include <cmath>
#include <Math.h>
#include <Geometry.h>

double
geometry::adjacent(double tiltAngleDeg, double hypotenuse)
{
    return std::cos(degToRad(tiltAngleDeg)) * hypotenuse;
}

double
geometry::opposite(double tiltAngleDeg, double hypotenuse)
{
    return std::sin(degToRad(tiltAngleDeg)) * hypotenuse;
}

double
geometry::tiltAngleDeg(double opposite, double adjacent)
{
    return radToDeg(std::atan2(opposite, adjacent));
}

double
geometry::hypotenuse(double opposite, double adjacent)
{
    return std::sqrt((opposite * opposite) + (adjacent * adjacent));
}

double
geometry::hypotenuse(double tiltAngleDeg, Opposite &opposite)
{
    return opposite.lenght / std::sin(degToRad(tiltAngleDeg));
}

double
geometry::hypotenuse(double tiltAngleDeg, Adjacent &adjacent)
{
    return adjacent.lenght / std::cos(degToRad(tiltAngleDeg));
}

Vector
geometry::rotate(const Vector &v, double angleAroundXDeg,
        double angleAroundYDeg, double angleAroundZDeg) {
    Vector out;

    out = *(rotationMatrixOnX(angleAroundXDeg).get()) * v;
    out = *(rotationMatrixOnY(angleAroundYDeg).get()) * out;
    out = *(rotationMatrixOnZ(angleAroundZDeg).get()) * out;

    return out;
}