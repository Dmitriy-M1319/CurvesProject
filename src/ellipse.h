#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "curve.h"

namespace Curves
{
    class Ellipse: public Curve
    {
    public:
        Ellipse(const float& radius_first, const float& radius_second);
        Point calc_point(float t) override;
        Vector calc_derivative(float t) override;
        float get_radius_first();
        float get_radius_second();
    private:
        float radius_first;
        float radius_second;
    };
};

#endif
