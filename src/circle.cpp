#include "circle.h"
#include <cmath>
#include <stdexcept>

using namespace Curves;


Circle::Circle(const float& radius) 
{
    if(radius <= 0)
        throw std::invalid_argument{"Incorrect radius value"};

    this->radius = radius;
}


float Circle::get_radius()
{
    return radius;
}


Point Circle::calc_point(float t)
{
    return Point{radius * std::cos(t), radius * std::sin(t), 0}; 
}


Vector Circle::calc_derivative(float t)
{
    return Point{-radius * std::sin(t), radius * std::cos(t), 1}; 
}


