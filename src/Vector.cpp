#include <cmath>
#include <Math.h>
#include <Vector.h>
#include <Format.h>

Vector::Vector()
{
    m_v[Coord::X] = 0;
    m_v[Coord::Y] = 0;
    m_v[Coord::Z] = 0;
}

Vector::Vector(double x, double y, double z)
{
    m_v[Coord::X] = x;
    m_v[Coord::Y] = y;
    m_v[Coord::Z] = z;
}

double
Vector::length() const
{
    const Vector& a = *this;

    return std::sqrt(a.dot(a));
}

double
Vector::dot(const Vector& b) const
{
    const Vector& a = *this;

    return  a[Coord::X] * b[Coord::X] +
            a[Coord::Y] * b[Coord::Y] +
            a[Coord::Z] * b[Coord::Z];
}

Vector
Vector::normalized() const
{
    double a = 1.0 / length();

    return a * (*this);
}

double&
Vector::operator[](Coord pos)
{
    return m_v[pos];
}

double const &
Vector::operator[](Coord pos) const
{
    return m_v[pos];
}

Vector
operator+(const Vector& a, const Vector& b)
{
    return Vector(
        a[Coord::X] + b[Coord::X],
        a[Coord::Y] + b[Coord::Y],
        a[Coord::Z] + b[Coord::Z]
    );
}

Vector
operator-(const Vector& a, const Vector& b)
{
    return Vector(
        a[Coord::X] - b[Coord::X],
        a[Coord::Y] - b[Coord::Y],
        a[Coord::Z] - b[Coord::Z]
    );
}

Vector
operator*(double a, const Vector&b)
{
    return Vector(
        a * b[Coord::X],
        a * b[Coord::Y],
        a * b[Coord::Z]
    );
}

std::ostream&
operator<<(std::ostream& os, const Vector& a)
{
    os << fmt::fos(' ', 8, 3) << a[Coord::X];
    os << std::endl;
    os << fmt::fos(' ', 8, 3) << a[Coord::Y];
    os << std::endl;
    os << fmt::fos(' ', 8, 3) << a[Coord::Z];

    return os;
}

double
distance(const Vector& a, const Vector& b)
{
    return (a - b).length();
}

bool
close(const Vector& a, const Vector& b, double epsilon)
{
    double d = distance(a, b);

    return math::close(d, 0, epsilon);
}