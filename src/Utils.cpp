#include <Utils.h>
#include <cassert>
#include <cmath>

void
utils::TestData::populate(Raceway& raceway,
    utils::TestData::NamedEndpoints& eps,
    utils::TestData::NamedSegments& segs)
{
    for (TestEndpoint endpoint : endpoints) {
        Endpoint_H tuple = Endpoint_H(new Endpoint(Vector(endpoint.x, endpoint.y, endpoint.z)));
        eps.insert(std::pair<std::string, Endpoint_H>(endpoint.name, tuple));
        raceway.add_endpoint(tuple);
    }

    for (TestSegment segment : segments) {
        Segment_H tuple = Segment_H(new Segment(eps[segment.start_name], eps[segment.end_name]));
        segs.insert(std::pair<std::string, Segment_H>(segment.name, tuple));
        raceway.add_segment(tuple);
    }
}