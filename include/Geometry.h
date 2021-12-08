#pragma once

#include <memory>
#include <Vector.h>
#include <Matrix.h>

using namespace math;

namespace geometry {

    /**
     * @brief 2D Vectors geometry: a right triangle ihas one angle with a value
     * of 90 degrees (M_PI / 2 radians) and it is composed by three 2D
     * vectors named "sides": the hypotenuse side, the opposite side and
     * the adjacent side
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
     * t is the "tilt" angle of the hypotenuse in radians.
     */

    /**
     * @brief Implement a generic side of a polygon.
     * We have just the lenght of the side for now.
     * 
     * Note: it could be used a Vector as a Side,
     * but for now I would not like to add this dependency.
     * These three structs are useful just to implement
     * the right overloading for the hypotenuse functions.
     */
    struct Side {
        Side(double lenght = 1.0) {
            this->lenght = lenght;
        }

        double lenght;
    };

    /**
     * @brief Implement the opposite side of a right triangle
     */
    struct Opposite : Side {
        Opposite(double lenght = 1.0) : Side(lenght) { }
    };

    /**
     * @brief Implement the adjacent side of a right triangle
     */
    struct Adjacent : Side {
        Adjacent(double lenght = 1.0) : Side(lenght) { }
    };

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
     * @brief Calculates the hypotenuse
     * 
     * @param tiltAngleDeg 
     * @param opposite 
     * @return double 
     */
    double
    hypotenuse(double tiltAngleDeg, Opposite &opposite);

    /**
     * @brief Calculates the hypotenuse
     * 
     * @param tiltAngleDeg 
     * @param adjacent 
     * @return double 
     */
    double
    hypotenuse(double tiltAngleDeg, Adjacent &adjacent);

    /**
     * @brief 3D Vectors geometry: rotation functions
     */
    namespace {
        /**
         * @brief Returns the rotation matrix on X-axis
         * 
         * @param angleDeg 
         * @return std::unique_ptr<Matrix> 
         */
        std::unique_ptr<Matrix>
        rotationMatrixOnX(double angleDeg) {
            return std::unique_ptr<Matrix>(new Matrix({
                Vector(  1,  0                           ,  0                             ),
                Vector(  0,  std::cos(degToRad(angleDeg)),  std::sin(degToRad(angleDeg))  ),
                Vector(  0, -std::sin(degToRad(angleDeg)),  std::cos(degToRad(angleDeg))  )
            }));
        }

        /**
         * @brief Returns the rotation matrix on Y-axis
         * 
         * @param angleDeg 
         * @return std::unique_ptr<Matrix> 
         */
        std::unique_ptr<Matrix>
        rotationMatrixOnY(double angleDeg) {
            return std::unique_ptr<Matrix>(new Matrix({
                Vector(  std::cos(degToRad(angleDeg)),  0, -std::sin(degToRad(angleDeg))  ),
                Vector(  0                           ,  1,  0                             ),
                Vector(  std::sin(degToRad(angleDeg)),  0,  std::cos(degToRad(angleDeg))  )
            }));
        }

        /**
         * @brief Returns the rotation matrix on Z-axis
         * 
         * @param angleDeg 
         * @return std::unique_ptr<Matrix> 
         */
        std::unique_ptr<Matrix>
        rotationMatrixOnZ(double angleDeg) {
            return std::unique_ptr<Matrix>(new Matrix({
                Vector(  std::cos(degToRad(angleDeg)),  std::sin(degToRad(angleDeg)), 0  ),
                Vector( -std::sin(degToRad(angleDeg)),  std::cos(degToRad(angleDeg)), 0  ),
                Vector(  0                           ,  0                           , 1  )
            }));
        }
    }

    /**
     * @brief rotate a vector in 3D space using right-hand rule
     * 
     * @param v 
     * @param angleAroundXDeg 
     * @param angleAroundYdeg 
     * @param angleAroundZDeg 
     * @return Vector 
     */
    Vector
    rotate(const Vector &v, double angleAroundXDeg,
            double angleAroundYdeg, double angleAroundZDeg);
}