#pragma once

#include <cmath>
#include <iostream>
#include <Math.h>
#include <Vector.h>

/**
 * @brief Very simple 3x3 column-wise Matrix implementation
 */
class Matrix
{

public:
    /**
     * @brief Construct a new Matrix object
     */
    Matrix();

    /**
     * @brief Construct a new Matrix object
     * 
     * @param col0
     * @param col1 
     * @param col2 
     */
    Matrix(Vector col0, Vector col1, Vector col2);

    /**
     * @brief subscript operator
     * 
     * @param pos 
     * @return Vector& 
     */
    Vector&
    operator[](size_t pos);

    /**
     * @brief subscript operator
     * 
     * @param pos 
     * @return Vector const& 
     */
    Vector const &
    operator[](size_t pos) const;

    /**
     * @brief Multiplication between the Matrix and a column Vector.
     * It returns a column Vector
     * 
     * @param v 
     * @return Vector 
     */
    Vector
    operator*(const Vector &v) const;

private:
    /**
     * @brief 3 column vectors initialized at zero
     */
    std::array<Vector, 3> cols;
};

std::ostream &
operator<<(std::ostream &os, Matrix const &m);