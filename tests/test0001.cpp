#include <tests.h>

TEST_CASE( "[test 1] Test segment distance function", "[test 1]")
{
    Endpoint_H start(new Endpoint(Vector(0, 0, 0)));
    Endpoint_H end  (new Endpoint(Vector(3, 4, 0)));

    Segment_H segment(new Segment(start, end));

    CHECK(segment->lenght() == 5.0);
}