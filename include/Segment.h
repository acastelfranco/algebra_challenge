#ifndef SEGMENT_H
#define SEGMENT_H

#include <Endpoint.h>
#include <memory>

class Segment;
using Segment_H = std::shared_ptr<Segment>;

/**
 * @brief Represents a segment in the raceway.  A segment is created with the
 * endpoints at the start and end of the segment.
 */
class Segment
{
public:
    Segment(Endpoint_H start_, Endpoint_H end_);

    /**
     * @brief Get the start endpoint
     * 
     * @return Endpoint_H 
     */
    Endpoint_H start() const;

    /**
     * @brief Get the end endpoint
     * 
     * @return Endpoint_H 
     */
    Endpoint_H end() const;

    /**
     * @brief Get the start endpoint position
     * 
     * @return const Vector& 
     */
    const Vector& start_pos() const;

    /**
     * @brief Get the end endpoint position
     * 
     * @return const Vector& 
     */
    const Vector& end_pos() const;

    /**
     * @brief Compute the lenght of the segment
     * 
     * @return const double 
     */
    const double lenght() const;

private:

    /**
     * @brief start endpoint
     */
    Endpoint_H m_start;

    /**
     * @brief end endpoint
     * 
     */
    Endpoint_H m_end;
};

#endif
