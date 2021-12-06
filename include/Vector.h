#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>

/**
 * @brief Represents a point or a vector with 3D Cartesian coordinates.
 */
class Vector
{
public:
    Vector();
    Vector(double x, double y, double z);

    /**
     * @brief Returns the length of the vector.
     * 
     * @return double 
     */
    double length() const;

    /**
     * @brief Returns the dot product of this vector with another one.
     * 
     * @param b 
     * @return double 
     */
    double dot(const Vector& b) const;

    /**
     * @brief Returns a new vector with the same direction but having length 1.
     * 
     * @return Vector 
     */
    Vector normalized() const;

    /**
     * @brief The coordinates of the vector are public.
     */
    double m_v[3];
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
Vector operator+(const Vector& a, const Vector& b);

/**
 * @brief Vector subtraction
 * 
 * @param a 
 * @param b 
 * @return Vector 
 */
Vector operator-(const Vector& a, const Vector& b);

/**
 * @brief Scalar/vector multiplication.
 * 
 * @param a 
 * @param b 
 * @return Vector 
 */
Vector operator*(double a, const Vector&b);

/**
 * @brief Output the std::ostream for debugging.
 * 
 * @param os 
 * @param a 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Vector& a);

/**
 * @brief Returns distance between two points.
 * 
 * @param a 
 * @param b 
 * @return double 
 */
double distance(const Vector& a, const Vector& b);


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
