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
}