#pragma once

namespace math {

    /**
     * @brief Implement a generic side of a polygon.
     * We have just the lenght of the side for now.
     * 
     * Note: it could be used a Segment as a Side,
     * but for now I would not like to add this dependency.
     * These three structs are just to implement the right
     * overloading for the hypotenuse functions .
     */
    struct Side { double lenght; };

    /**
     * @brief Implement the opposite side of a right triangle
     */
    struct Opposite : public Side { };

    /**
     * @brief Implement the adjacent side of a right triangle
     */
    struct Adjacent : public Side { }; 

    /**
     * @brief Returns whether two numbers are close within an epsilon.
     * 
     * @param a 
     * @param b 
     * @param epsilon 
     * @return true 
     * @return false 
     */

    bool
    close(double a, double b, double epsilon = 1e-4);

    /**
     * @brief A right triangle has one angle with a value of 90 degrees
     * (M_PI / 2 radians).
     * 
     * The three trigonometric functions most often used to solve for
     * a missing side of a right triangle are:
     * 
     * sin(t) = opposite / hypotenuse
     * cos(t) = adjacent / hypotenuse
     * tan(t) = opposite / adjacent
     * 
     * Plus the tangent can be expressed using sine and cosine functions:
     * 
     * tan(t) = sin(t)   / cos(t)
     * 
     * t is the "tilt" angle in radians.
     */

    /**
     * @brief Converts angle in degrees into angle in radians
     * 
     * @param angleDeg 
     * @return constexpr double 
     */
    constexpr double
    degToRad(double angleDeg) {
        return angleDeg * M_PI / 180.0;
    }

    /**
     * @brief Converts angle in radians into angle in degrees
     * 
     * @param angleRad 
     * @return constexpr double 
     */
    constexpr double
    radToDeg(double angleRad) {
        return angleRad * 180.0 / M_PI;
    }

    /**
     * @brief This function calculates the adjacent side(base) of a right triangle
     * 
     * @param tiltAngleDeg 
     * @param hypotenuse 
     * @return double 
     */
    double
    adjacent(double tiltAngleDeg, double hypotenuse);

    /**
     * @brief This function calculates the opposite side(height) of a right triangle
     * 
     * @param tiltAngleDeg 
     * @param hypotenuse 
     * @return double 
     */
    double
    opposite(double tiltAngleDeg, double hypotenuse);

    /**
     * @brief Calculates the triangle hypotenuse tilt angle
     * 
     * @param opposite 
     * @param adjacent 
     * @return double 
     */
    double
    tiltAngleDeg(double opposite, double adjacent);

    /**
     * @brief Calculates the hypotenuse
     * 
     * @param opposite 
     * @param adjacent 
     * @return double 
     */
    double
    hypotenuse(double opposite, double adjacent);

    /**
     * @brief 
     * 
     * @param tiltAngleDeg 
     * @param opposite 
     * @return double 
     */
    double
    hypotenuse(double tiltAngleDeg, Opposite &opposite);

    /**
     * @brief 
     * 
     * @param tiltAngleDeg 
     * @param adjacent 
     * @return double 
     */
    double
    hypotenuse(double tiltAngleDeg, Adjacent &adjacent);
}