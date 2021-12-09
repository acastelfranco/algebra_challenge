#ifndef VECTOR_H
#define VECTOR_H

#include <array>
#include <ostream>
#include <cmath>

/**
 * @brief forward declaration for the SphericalVector cast operator
 */
class Vector;

/**
 * @brief Polar vector class
 * Class describing a vector using spherical coordinates
 * (ISO 80000-2:2019)
 * 
 * - from cartesian to polar coordinates -
 * radius(r)          = sqrt(x * x + y * y + z * z)
 * inclination(theta) = acos(z / r)
 * azimut(fi)         = atan2(y, x)
 * 
 * - from polar to cartesian coordinates -
 * x = radius * cos(azimuth) * sin(inclination)
 * y = radius * sin(azimuth) * sin(inclination)
 * z = radius * cos(inclination)
 * 
 * - distance from a to b -
 * d = sqrt(
 *      ((a.radius * a.radius) + (b.radius * b.radius)) -
 *      (2 * a.radius * b.radius * cos(a.inclination - b.inclination)) -
 *      (2 * a.radius * b.radius * sin(a.inclination) * sin(b.inclination) *
 *      (cos(a.azimuth - b.azimuth) - 1))
 * )
 */

class SphericalVector {
public:

    /**
     * @brief Construct a new Polar Vector object
     * 
     * @param radius 
     * @param inclination 
     * @param azimuth 
     */
    SphericalVector(double radius = 0.0, double inclination = 0.0, double azimuth = 0.0) :
        radius(radius), inclination(inclination), azimuth(azimuth) { }

    /**
     * @brief cast operator from SphericalVector to Vector
     * 
     * @return Vector 
     */
    operator Vector() const;

    double radius;
    double inclination;
    double azimuth;
};

/**
 * @brief coordinates indexes
 */
enum Coord { X = 0, Y = 1, Z = 2 };

/**
 * @brief Represents a point or a vector with 3D Cartesian coordinates.
 */
class Vector
{
public:
    /**
     * @brief Construct a new Vector object
     */
    Vector();

    /**
     * @brief Construct a new Vector object
     * 
     * @param x 
     * @param y 
     * @param z 
     */
    Vector(double x, double y, double z);

    /**
     * @brief Returns the length of the vector.
     * 
     * @return double 
     */
    double
    length() const;

    /**
     * @brief Returns the dot product of this vector with another one.
     * 
     * @param b 
     * @return double 
     */
    double
    dot(const Vector& b) const;

    /**
     * @brief Returns a new vector with the same direction but having length 1.
     * 
     * @return Vector 
     */
    Vector
    normalized() const;

    /**
     * @brief subscript operator
     * 
     * @param pos 
     * @return double& 
     */
    double&
    operator[](Coord pos);

    /**
     * @brief subscript operator
     * 
     * @param pos 
     * @return double const& 
     */
    double const &
    operator[](Coord pos) const;

    /**
     * @brief cast operator from Vector to SphericalVector
     * 
     * @return SphericalVector 
     */
    operator SphericalVector() const;

private:
    /**
     * @brief The coordinates of the vector are public.
     */
    std::array<double, 3> m_v;
};

/**
 * operators and free functions
 */

/**
 * @brief Vector addition
 * 
 * @param a 
 * @param b 
 * @return Vector 
 */
Vector
operator+(const Vector& a, const Vector& b);

/**
 * @brief Vector subtraction
 * 
 * @param a 
 * @param b 
 * @return Vector 
 */
Vector
operator-(const Vector& a, const Vector& b);

/**
 * @brief Scalar/vector multiplication.
 * 
 * @param a 
 * @param b 
 * @return Vector 
 */
Vector
operator*(double a, const Vector&b);

/**
 * @brief Output the std::ostream for debugging.
 * 
 * @param os 
 * @param a 
 * @return std::ostream& 
 */
std::ostream&
operator<<(std::ostream& os, const Vector& a);

/**
 * @brief Output the std::ostream for debugging.
 * 
 * @param os 
 * @param a 
 * @return std::ostream& 
 */
std::ostream&
operator<<(std::ostream& os, const SphericalVector& a);

/**
 * @brief Returns distance between two points.
 * 
 * @param a 
 * @param b 
 * @return double 
 */
double
distance(const Vector& a, const Vector& b);

/**
 * @brief Returns the distance between two points in polar coordinates
 * 
 * @param a 
 * @param b 
 * @return double 
 */
double
distance(const SphericalVector& a, const SphericalVector& b);

/**
 * @brief Returns whether the distance between two points is within an epsilon.
 * 
 * @param a 
 * @param b 
 * @param epsilon 
 * @return true 
 * @return false 
 */
bool
close(const Vector& a, const Vector& b, double epsilon = 1e-4);

#endif
