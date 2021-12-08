#include <tests.h>

TEST_CASE( "[test 1] Test segment distance function", "[test 1]")
{
    SECTION("check a first segment")
    {
        Endpoint_H start(new Endpoint(Vector(0, 0, 0)));
        Endpoint_H end  (new Endpoint(Vector(3, 4, 0)));

        Segment_H segment(new Segment(start, end));

        CHECK(segment->lenght() == 5.0);
    }

    SECTION("check a second segment using 2D geometry functions")
    {
        double desiredLenght = 22.0;
        double vectorTiltAngleDeg = 30.0;
        double endHeight = opposite(vectorTiltAngleDeg, desiredLenght);
        double endBase   = adjacent(vectorTiltAngleDeg, desiredLenght);

        Endpoint_H start(new Endpoint(Vector(0, 0, 0)));
        Endpoint_H end  (new Endpoint(Vector(endBase, endHeight, 0)));

        Segment_H segment(new Segment(start, end));

        CHECK(segment->lenght() == desiredLenght);
    }
}