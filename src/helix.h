#ifndef HELIX_H
#define HELIX_H


#include "curve.h"

namespace Curves
{
    class Helix: public Curve
    {
    public:
        Helix(const float& radius, const float& step);
        Point calc_point(float t) override;
        Vector calc_derivative(float t) override;
        float get_radius();
        float get_step();
    private:
        float radius;
        float step;
    };
};

#endif
