#include <tests.h>

TEST_CASE( "[test 102] Create a raceway with 4 endpoints and 3 segments "
            "and check segments and reinforcements", "[test 102]" )
{
    TestData data = {
        // endpoints
        {
            {"a", 0, 0, 0},
            {"b", 0, 10, 0},
            {"c", 0, -10, 0},
            {"d", 10, 0, 0},
        },

        // segments
        {
            {"x", "a", "b"},
            {"y", "a", "c"},
            {"z", "a", "d"},
        }
    };
    
    Raceway raceway;
    TestData::NamedEndpoints endpoints;
    TestData::NamedSegments segments;
    data.populate(raceway, endpoints, segments);

    // compute supports
    Supports supports;
    SupportsService::computeSupports(raceway, supports);

    SECTION("check segment \"x\"")
    {
        Segment_H seg = segments["x"];
        CHECK(supports[seg].size() == 2);
        CHECK(close(distance(supports[seg].front(), seg->start_pos()), 1.0));
        CHECK(close(distance(supports[seg].back(), seg->end_pos()), 1.0));
    }

    SECTION("check segment \"y\"")
    {
        Segment_H seg = segments["y"];
        CHECK(supports[seg].size() == 2);
        CHECK(close(distance(supports[seg].front(), seg->start_pos()), 1.0));
        CHECK(close(distance(supports[seg].back(), seg->end_pos()), 1.0));
    }

    SECTION("check segment \"z\"")
    {
        Segment_H seg = segments["z"];
        CHECK(supports[seg].size() == 2);
        CHECK(close(distance(supports[seg].front(), seg->start_pos()), 1.0));
        CHECK(close(distance(supports[seg].back(), seg->end_pos()), 1.0));
    }

    SECTION("check endpoints a,b,c,d reinforcements")
    {
        CHECK(endpoints["a"]->reinforced() == true);
        CHECK(endpoints["b"]->reinforced() == false);
        CHECK(endpoints["c"]->reinforced() == false);
        CHECK(endpoints["d"]->reinforced() == false);
    }
}
