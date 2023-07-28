#include "helix.h"
#include <cmath>

using namespace Curves;


Helix::Helix(const float& radius, const float& step): 
    radius(radius), step(step / (2 * M_PIf)) {}


float Helix::get_radius()
{
    return radius;
}


float Helix::get_step()
{
    return step;
}


Point Helix::calc_point(float t)
{
    return Point{radius * std::cos(t), radius * std::sin(t), step * t};
}


Vector Helix::calc_derivative(float t)
{
    return Vector{-radius * std::sin(t), radius * std::cos(t), step};
}
