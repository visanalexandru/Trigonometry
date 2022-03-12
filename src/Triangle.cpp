//
// Created by visan on 3/8/22.
//

#include "Triangle.h"

namespace Trigonometry {

    Triangle::Triangle(Angle _a, Angle _b) : a(_a), b(_b) {
        c = Angle(M_PI) - a - b;
        //Sort the angles
        if (b < a) {
            std::swap(a, b);
        }
        if (c < a) {
            std::swap(a, c);
        }
        if (b > c) {
            std::swap(b, c);
        }
    }


    Angle Triangle::smallestAngle() const {
        return a;
    }

    Triangle::Sides Triangle::sides(double smallest_side) const {
        // Apply the law of the sines
        // a / sin(a) = b / sin(b) = c / sin(c)
        double ratio = smallest_side / smallestAngle().sin();

        Sides result = {smallest_side, ratio * b.sin(), ratio * c.sin()};
        return result;
    }

    double Triangle::area(double smallest_side) const {
        auto s = sides(smallest_side);
        //The angle of the triangle is equal to b * c * sin(A) / 2 where a represents the angle between the sides a and b.

        double area = s.b * s.c * smallestAngle().sin() / 2;
        return area;
    }

    bool Triangle::acute() const {
        //Since c is the biggest angle, check if it is less than pi/2.
        return c.radians() < (M_PI / 2);
    }
}
