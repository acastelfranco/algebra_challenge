#ifndef COMPUTE_SUPPORTS_H
#define COMPUTE_SUPPORTS_H

#include <map>
#include <vector>

#include <Raceway.h>
#include <Vector.h>

using Supports = std::map<Segment_H, std::vector<Vector>>;

/**
 * @brief Compute the locations of supports for all segments in the raceway.
 * Also set the endpoints to be reinforced as required.
 * 
 * @param raceway 
 * @param supports 
 */
void compute_supports(Raceway& raceway, Supports& supports);

#endif
