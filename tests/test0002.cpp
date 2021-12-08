#include <tests.h>

TEST_CASE("[test 2] Test 3D geometry functions", "[test 2]") {

    Matrix m1(Vector(1.0, 2.0, 3.0), Vector(4.0, 5.0, 6.0), Vector(7.0, 8.0, 9.0));
    
    SECTION ("check matrix column wise construction") {
        CHECK(m1[0][Coord::X] == 1.0);
        CHECK(m1[0][Coord::Y] == 2.0);
        CHECK(m1[0][Coord::Z] == 3.0);
        CHECK(m1[1][Coord::X] == 4.0);
        CHECK(m1[1][Coord::Y] == 5.0);
        CHECK(m1[1][Coord::Z] == 6.0);
        CHECK(m1[2][Coord::X] == 7.0);
        CHECK(m1[2][Coord::Y] == 8.0);
        CHECK(m1[2][Coord::Z] == 9.0);
    }

    SECTION ("check matrix column wise copy constructor and assignment operator") {
        Matrix m2 = m1;

        CHECK(m2[0][Coord::X] == 1.0);
        CHECK(m2[0][Coord::Y] == 2.0);
        CHECK(m2[0][Coord::Z] == 3.0);
        CHECK(m2[1][Coord::X] == 4.0);
        CHECK(m2[1][Coord::Y] == 5.0);
        CHECK(m2[1][Coord::Z] == 6.0);
        CHECK(m2[2][Coord::X] == 7.0);
        CHECK(m2[2][Coord::Y] == 8.0);
        CHECK(m2[2][Coord::Z] == 9.0);
    }

    Vector a(1, 2, 3);
    Vector out = a;
    
    out = geometry::rotate(out, 40, 0, 0);
    SECTION ("check vector rotation around X axis") {
        CHECK(close(out[Coord::X],  1.000, 1e-2));
        CHECK(close(out[Coord::Y], -0.396, 1e-2));
        CHECK(close(out[Coord::Z],  3.584, 1e-2));
    }

    out = geometry::rotate(out, 0, 33, 0);
    SECTION ("check vector rotation around Y axis") {
        CHECK(close(out[Coord::X],  2.790, 1e-2));
        CHECK(close(out[Coord::Y], -0.396, 1e-2));
        CHECK(close(out[Coord::Z],  2.461, 1e-2));
    }

    out = geometry::rotate(out, 0, 0, 67);
    SECTION ("check vector rotation around Z axis") {
        CHECK(close(out[Coord::X],  1.455, 1e-2));
        CHECK(close(out[Coord::Y],  2.414, 1e-2));
        CHECK(close(out[Coord::Z],  2.461, 1e-2));
    }

    out = geometry::rotate(a, 40, 33, 67);
    SECTION ("check vector rotation around all three axis") {
        CHECK(close(out[Coord::X],  1.455, 1e-2));
        CHECK(close(out[Coord::Y],  2.414, 1e-2));
        CHECK(close(out[Coord::Z],  2.461, 1e-2));
    }
}
