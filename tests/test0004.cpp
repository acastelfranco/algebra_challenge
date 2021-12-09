#include <tests.h>

TEST_CASE("[test 4] Test getVectorOnSegment", "[test 4]") {
    Vector s(0,  0, 0);
    Vector e(0, 10, 0);
    Vector c = geometry::getVectorOnSegment(s, e, 3.0);

    SECTION("check distance of the translated vector") {
        CHECK(close(distance(s, c), 3.0));
    }
}