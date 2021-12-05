#ifndef RACEWAY_H
#define RACEWAY_H

#include <set>

#include <Segment.h>
#include <Endpoint.h>

/**
 * @brief Represents a Raceway graph.  This stores the Segment and Endpoint
 * objects that make up the graph.  The graph can be built by adding
 * endpoints and segments and can be queried.
 */
class Raceway
{
public:
    using Segments = std::set<Segment_H>;
    using Endpoints = std::set<Endpoint_H>;
    
    Raceway() = default;

    /**
     * @brief Add an endpoint to the raceway.
     * 
     * @param endpoint 
     */
    void add_endpoint(Endpoint_H endpoint);

    /**
     * @brief Add a segment to the raceway.  Both endpoints of the segment
     * must be populated, and must already be stored in the
     * raceway.
     * 
     * @param segment 
     */
    void add_segment(Segment_H segment);

    /**
     * @brief Get the endpoints
     * 
     * @return const Endpoints 
     */
    const Endpoints endpoints() const;

    /**
     * @brief Get the segments
     * 
     * @return const Segments& 
     */
    const Segments& segments() const;

    /**
     * @brief Return the degree (in the graph theory sense) of an endpoint in
     * the raceway.  The degree is the number of segments in the
     * raceway that use this endpoint.
     * 
     * @param endpoint 
     * @return int 
     */
    int degree(Endpoint_H endpoint) const;

private:
    Segments m_segments;
    Endpoints m_endpoints;

    /**
     * @todo: you may add more data members here
     */
};

#endif
