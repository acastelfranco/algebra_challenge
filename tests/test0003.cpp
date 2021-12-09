#include <tests.h>

TEST_CASE("[test 3] Test SphericalVector", "[test 3]") {
    Vector a(1, 2, 3);
    Vector b(4, 5, 6);
    
    SphericalVector A = (SphericalVector) a;
    SphericalVector B = (SphericalVector) b;

    SECTION("Test coordinates correctness using distance") {
        CHECK(close(distance(a, b), distance(A, B), 1e-12));
    }

    a = (Vector) A;
    b = (Vector) B;

    SECTION("Test coordinates correctness after casting back to cartesian coordinates") {
        CHECK(close(a[Coord::X], 1.0, 1e-12));
        CHECK(close(a[Coord::Y], 2.0, 1e-12));
        CHECK(close(a[Coord::Z], 3.0, 1e-12));
        CHECK(close(b[Coord::X], 4.0, 1e-12));
        CHECK(close(b[Coord::Y], 5.0, 1e-12));
        CHECK(close(b[Coord::Z], 6.0, 1e-12));
    }
}