#include <Utils.h>
#include <cassert>
#include <cmath>

bool
utils::math::close(double a, double b, double epsilon)
{
    return std::fabs(a - b) < epsilon;
}

void
utils::testdata::TestData::populate(Raceway& raceway,
    utils::testdata::TestData::NamedEndpoints& eps,
    utils::testdata::TestData::NamedSegments& segs)
{
    assert(!"unimplemented");
}