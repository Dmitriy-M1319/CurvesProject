#ifndef CURVE_H
#define CURVE_H

#include <tuple>

using Point = std::tuple<float, float, float>;
using Vector = std::tuple<float, float, float>;


namespace Curves
{
    class Curve
    {
    public:
        virtual Point calc_point(float t) = 0;
        virtual Vector calc_derivative(float t) = 0;
        virtual ~Curve();
    };
};

#endif
