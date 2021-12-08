#include <Matrix.h>
#include <Format.h>

Matrix::Matrix()
{
    cols = {
        Vector(0.0, 0.0, 0.0),
        Vector(0.0, 0.0, 0.0),
        Vector(0.0, 0.0, 0.0)
    };
}

Matrix::Matrix(Vector col0, Vector col1, Vector col2)
{
    cols[0] = col0;
    cols[1] = col1;
    cols[2] = col2;
}

Vector
Matrix::operator*(const Vector &v) const
{
    return Vector(
        cols[0][Coord::X] * v[Coord::X] +
        cols[1][Coord::X] * v[Coord::Y] +
        cols[2][Coord::X] * v[Coord::Z],

        cols[0][Coord::Y] * v[Coord::X] +
        cols[1][Coord::Y] * v[Coord::Y] +
        cols[2][Coord::Y] * v[Coord::Z],

        cols[0][Coord::Z] * v[Coord::X] +
        cols[1][Coord::Z] * v[Coord::Y] +
        cols[2][Coord::Z] * v[Coord::Z]
    );
}

Vector &
Matrix::operator[](size_t pos)
{
    return cols[pos];
}

Vector const &
Matrix::operator[](size_t pos) const
{
    return cols[pos];
}

std::ostream &
operator<<(std::ostream &os, Matrix const &m)
{
    os << fmt::fos(' ', 8, 3) << m[0][Coord::X] << " ";
    os << fmt::fos(' ', 8, 3) << m[1][Coord::X] << " ";
    os << fmt::fos(' ', 8, 3) << m[2][Coord::X] << " ";
    os << std::endl;

    os << fmt::fos(' ', 8, 3) << m[0][Coord::Y] << " ";
    os << fmt::fos(' ', 8, 3) << m[1][Coord::Y] << " ";
    os << fmt::fos(' ', 8, 3) << m[2][Coord::Y] << " ";
    os << std::endl;

    os << fmt::fos(' ', 8, 3) << m[0][Coord::Z] << " ";
    os << fmt::fos(' ', 8, 3) << m[1][Coord::Z] << " ";
    os << fmt::fos(' ', 8, 3) << m[2][Coord::Z] << " ";

    return os;
}