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

Vector::operator SphericalVector() const
{
    double radius = std::sqrt (
                        (m_v[Coord::X] * m_v[Coord::X]) +
                        (m_v[Coord::Y] * m_v[Coord::Y]) +
                        (m_v[Coord::Z] * m_v[Coord::Z])
                    );
    double inclination = math::radToDeg(std::acos(m_v[Coord::Z] / radius));
    double azimuth     = math::radToDeg(std::atan2(m_v[Coord::Y], m_v[Coord::X]));

    return SphericalVector(radius, inclination, azimuth);
}

SphericalVector::operator Vector() const {
    double x = radius * std::cos(math::degToRad(azimuth)) * std::sin(math::degToRad(inclination));
    double y = radius * std::sin(math::degToRad(azimuth)) * std::sin(math::degToRad(inclination));
    double z = radius * std::cos(math::degToRad(inclination));

    return Vector(x, y, z);
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

std::ostream&
operator<<(std::ostream& os, const SphericalVector& a){
    os << "radius:      " << fmt::fos(' ', 8, 3) << a.radius;
    os << std::endl;
    os << "inclination: " << fmt::fos(' ', 8, 3) << a.inclination << " (degs)";
    os << " "             << fmt::fos(' ', 8, 3) << math::degToRad(a.inclination) << " (radians)";
    os << std::endl;
    os << "azimuth:     " << fmt::fos(' ', 8, 3) << a.azimuth << " (degs)";
    os << " "             << fmt::fos(' ', 8, 3) << math::degToRad(a.azimuth) << " (radians)";

    return os;
}

double
distance(const Vector& a, const Vector& b)
{
    return (a - b).length();
}

double
distance(const SphericalVector& a, const SphericalVector &b)
{
    return std::sqrt(
        ((a.radius * a.radius) + (b.radius * b.radius)) -
        (2 * a.radius * b.radius * cos(math::degToRad(a.inclination - b.inclination))) -
        (2 * a.radius * b.radius * sin(math::degToRad(a.inclination)) *
        sin(math::degToRad(b.inclination)) * (cos(math::degToRad(a.azimuth - b.azimuth)) - 1))
    );
}

bool
close(const Vector& a, const Vector& b, double epsilon)
{
    double d = distance(a, b);

    return math::close(d, 0, epsilon);
}