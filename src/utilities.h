#ifndef UTILITIES_H
#define UTILITIES_H

#include <cmath>
#include <limits>
#include <memory>

// Using

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 100.0;
}

// Common headers

#include "ray.h"
#include "vec3.h"

#endif //UTILITIES_H
