#include <tests.h>

TEST_CASE( "[test 101] Create a raceway with 2 endpoints and 3 segments "
            "and check segment x and reinforcements", "[test 101]")
{
    TestData data = {
        // endpoints
        {
            {"a", 0, 0, 0},
            {"b", 0, 10, 0},
        },

        // segments
        {
            {"x", "a", "b"},
        }
    };
    
    Raceway raceway;
    TestData::NamedEndpoints endpoints;
    TestData::NamedSegments segments;
    data.populate(raceway, endpoints, segments);

    // compute supports
    Supports supports;
    compute_supports(raceway, supports);

    SECTION("check segment \"x\"")
    {
        Segment_H x = segments["x"];
        CHECK(supports[x].size() == 2);
        CHECK(close(distance(supports[x].front(), x->start_pos()), 1.0));
        CHECK(close(distance(supports[x].back(), x->end_pos()), 1.0));
    }

    SECTION("check endpoint a and b reinforcements")
    {
        CHECK(endpoints["a"]->reinforced() == false);
        CHECK(endpoints["b"]->reinforced() == false);
    }
}
