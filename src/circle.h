#ifndef CIRCLE_H
#define CIRCLE_H

#include "curve.h"

namespace Curves
{
    class Circle: public Curve
    {
    public:
        Circle(const float& radius);
        Point calc_point(float t) override;
        Vector calc_derivative(float t) override;
        float get_radius();
    private:
        float radius;
    };
};

#endif
