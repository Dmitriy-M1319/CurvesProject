#include "curve.h"
#include "circle.h"
#include "ellipse.h"
#include "helix.h"
#include <iostream>
#include <tuple>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>


void fill_vector_random_curves(std::vector<Curves::Curve*> &curves)
{
    std::srand(std::time(NULL));
    // switch to enum
    int vector_size = 1 + std::rand() % 20; // from 1 to 18 
    for (int i = 0; i < vector_size; ++i) 
    {
        int curve_type = 1 + std::rand() % 4;
        float radius_first, step;
        switch (curve_type) 
        {
            case 1:
                // circle
                radius_first = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                curves.push_back(new Curves::Circle(radius_first));
                break;
            case 2:
                // ellipse
                radius_first = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                float radius_second = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                curves.push_back(new Curves::Ellipse(radius_first, radius_second));
                break;
            case 3:
                // helix
                radius_first = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                float step = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
                curves.push_back(new Curves::Helix(radius_first, step));
                break;
        }
    } 
}


void print_data(const std::vector<Curves::Curve*> &curves)
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


int main(int argc, char *argv[])
{
    return 0;
}
