#include <iostream>
#include <Utils.h>
#include <Raceway.h>
#include <compute_supports.h>

using namespace utils;

int
main()
{
    TestData data = {
        // endpoints
        {
            {"a", 0, 0, 0},
            {"d", 0, 29, 0},
        },

        // segments
        {
            {"z", "a", "d"}, 
        }
    };
    
    Raceway raceway;
    TestData::NamedEndpoints endpoints;
    TestData::NamedSegments segments;

    data.populate(raceway, endpoints, segments);

    std::cout << raceway << std::endl;

    // compute supports
    Supports supports;
    compute_supports(raceway, supports);

    return 0;
}
