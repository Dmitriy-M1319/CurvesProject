#include "curve.h"
#include "circle.h"
#include "ellipse.h"
#include "helix.h"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>


enum class CurveType 
{
    Circle = 1,
    Ellipse,
    Helix
};


void fill_vector_random_curves(std::vector<Curves::Curve *> &curves)
{
    std::srand(std::time(NULL));
    int vector_size = 1 + std::rand() % 20;
    for (int i = 0; i < vector_size; ++i) 
    {
        auto curve_type = static_cast<CurveType>(1 + std::rand() % 4);
        float radius_first, step;
        switch (curve_type) 
        {
            case CurveType::Circle:
                radius_first = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                curves.push_back(new Curves::Circle(radius_first));
                break;
            case CurveType::Ellipse:
                radius_first = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                float radius_second = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                curves.push_back(new Curves::Ellipse(radius_first, radius_second));
                break;
            case CurveType::Helix:
                radius_first = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                float step = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                curves.push_back(new Curves::Helix(radius_first, step));
                break;
        }
    } 
}


void print_data(const std::vector<Curves::Curve *> &curves)
{
    for (int i = 0; i < curves.size(); ++i) 
    {
        Point result_point = curves[i]->calc_point(M_PI_4f);
        Vector result_vector = curves[i]->calc_derivative(M_PI_4f);
        std::cout << "Object №" << i + 1 << ": Point {" 
            << std::get<0>(result_point) << ", "
            << std::get<1>(result_point) << ", "
            << std::get<2>(result_point) << "}, Derivative ("
            << std::get<0>(result_vector) << ", "
            << std::get<1>(result_vector) << ", "
            << std::get<2>(result_vector) << ")" << std::endl;
    }
}


void fill_vector_with_circles(const std::vector<Curves::Curve*> &curves,
        std::vector<Curves::Circle*> &circles)
{
    for (auto curve : curves) 
    {
        Curves::Circle *circle = dynamic_cast<Curves::Circle *>(curve);
        if (circle) 
            circles.push_back(circle);
    }
}


void print_circle_vector(const std::vector<Curves::Circle *> &circles)
{
    for (int i = 0; i < circles.size(); ++i) 
    {
        std::cout << "Circle №" << i + 1 << " with radius " << circles[i]->get_radius() << std::endl; 
    }
}


void sort_by_radius(std::vector<Curves::Circle *> &circles)
{
    std::sort(circles.begin(), circles.end(), [](Curves::Circle *a, Curves::Circle *b) {
            return a->get_radius() < b->get_radius();
            });
}


float calc_radius_sum(const std::vector<Curves::Circle *> &circles)
{
    float sum = 0;
    auto sum_func = [&](Curves::Circle *circle) { sum += circle->get_radius(); };
    std::for_each(circles.begin(), circles.end(), sum_func);
    return sum;
}


void clear_curves_memory(const std::vector<Curves::Curve *> &curves)
{
    auto free_func = [](Curves::Curve *curve) { delete curve; };
    std::for_each(curves.begin(), curves.end(), free_func);
}


int main(int argc, char *argv[])
{
    std::vector<Curves::Curve *> curves{};
    fill_vector_random_curves(curves);
    std::cout << "Points and derivatives" << std::endl;
    print_data(curves);
    std::cout << std::endl;

    std::vector<Curves::Circle *> circles{};
    fill_vector_with_circles(curves, circles);
    std::cout << "Circles non-sorted" << std::endl;
    print_circle_vector(circles);
    std::cout << std::endl;

    sort_by_radius(circles);
    std::cout << "Circles sorted" << std::endl;
    print_circle_vector(circles);
    std::cout << std::endl;

    float radius_sum = calc_radius_sum(circles);
    std::cout << "The sum of all radii is " << radius_sum << std::endl;
    
    clear_curves_memory(curves);
    curves.clear();
    circles.clear();
    return 0;
}
