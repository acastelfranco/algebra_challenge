#include <cassert>
#include <cmath>
#include <Geometry.h>
#include <compute_supports.h>

void
compute_supports(Raceway& raceway, Supports& supports)
{
    for (Segment_H segment : raceway.segments()) {
        Vector support;
        std::vector<Vector> sups_per_segment(0);

        // Add initial support
        support = geometry::getVectorOnSegment(segment->start_pos(), segment->end_pos(), 1.0);
        sups_per_segment.push_back(support);

        // Add additional supports
        int additionalSupports = std::floor(((segment->lenght() - 2.0) / constraints::maxSupportDistance));
        double distance = (additionalSupports > 0) ? (segment->lenght() - 2.0) / (additionalSupports + 1) : 0;

        double len = segment->lenght();

        for(int n = 0; n < additionalSupports; n++) {
            support = geometry::getVectorOnSegment(segment->start_pos(), segment->end_pos(), 1.0 + ((n + 1.0) * distance));
            sups_per_segment.push_back(support);
        }

        // Add final support
        support = geometry::getVectorOnSegment(segment->start_pos(), segment->end_pos(), segment->lenght() - 1.0);
        sups_per_segment.push_back(support);

        // Add supports to the computed list of supports for the current segments
        supports.insert(std::pair<Segment_H, std::vector<Vector>>(segment, sups_per_segment));
    }

    // Set reinforced endpoints
    for (Endpoint_H endpoint: raceway.endpoints()) {
        endpoint->set_reinforced(raceway.degree(endpoint) > 1);
    }
}
