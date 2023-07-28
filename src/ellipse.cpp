#include "ellipse.h"
#include <cmath>

using namespace Curves;


Ellipse::Ellipse(const float& radius_first, const float& radius_second): 
    radius_first(radius_first), radius_second(radius_second) {}


float Ellipse::get_radius_first()
{
    return radius_first;
}


float Ellipse::get_radius_second()
{
    return radius_second;
}

Point Ellipse::calc_point(float t)
{
    return Point{radius_first * std::cos(t), radius_second * std::sin(t), 0}; 
}


Vector Ellipse::calc_derivative(float t)
{
    return Point{-radius_first * std::sin(t), radius_second * std::cos(t), 1}; 
}
