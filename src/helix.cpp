#include "helix.h"
#include <cmath>
#include <stdexcept>

using namespace Curves;


Helix::Helix(const float& radius, const float& step)
{
    if(radius <= 0)
        throw std::invalid_argument{"Incorrect radius value"};

    this->radius = radius;
    this->step = step / (2 * M_PIf);
}


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
