#ifndef ENDPOINT_H
#define ENDPOINT_H

#include <memory>
#include <Vector.h>

class Endpoint;
using Endpoint_H = std::shared_ptr<Endpoint>;

/**
 * @brief Represents an endpoint in the raceway.  The endpoint has a 3D
 * position and a flag to indicate whether or not it needs to be
 * reinforced.
 */
class Endpoint
{
public:
    Endpoint(const Vector& pos);

    /**
     * @brief Set whether or not this endpoint needs to be reinforced.
     * 
     * @param reinforced_ 
     */
    void set_reinforced(bool reinforced_);

    /**
     * @brief Return whether or not this endpoint needs to be reinforced.
     * 
     * @return true 
     * @return false 
     */
    bool reinforced() const;

    /**
     * @brief Return the position of the endpoint in 3D Cartesian coordinates
     * 
     * @return const Vector& 
     */
    const Vector& position() const;

private:
    Vector m_pos;
    bool m_reinforced;
};

#endif
