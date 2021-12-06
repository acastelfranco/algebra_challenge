#pragma once

namespace math {
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
     * The three trigonometric functions most often used to solve for
     * a missing side of a right triangle are:
     * 
     * sin(t) = opposite / hypotenuse
     * cos(t) = adjacent / hypotenuse
     * tan(t) = opposite / adjacent
     * 
     * t is the angle is the hypotenuse tilt angle.
     */

    /**
     * @brief This function calculates the adjacent side(base) of a right triangle
     * 
     * @param tiltdeg 
     * @param hypotenuse 
     * @return double 
     */
    double
    adjacent(double tiltdeg, double hypotenuse);

    /**
     * @brief This function calculates the opposite side(height) of a right triangle
     * 
     * @param tiltdeg 
     * @param hypotenuse 
     * @return double 
     */
    double
    opposite(double tiltdeg, double hypotenuse);
}