//
// Created by visan on 3/8/22.
//

#ifndef ANGLE_TRIANGLE_H
#define ANGLE_TRIANGLE_H

#include"Angle.h"
#include<algorithm>
#include<iostream>

namespace Trigonometry {

    class Triangle {
    public:

    private:
        //The angles of the triangle.
        //The angles are ordered: a is the smallest angle, and c is the biggest angle.
        Angle a, b, c;
    public:

        //A struct to keep the lengths of the sides of the triangle.
        struct Sides {
            double a, b, c;
        };

        //Create the triangle given the two angles. The third angle is computed using the two.
        Triangle(Angle _a, Angle _b);

        //Returns the smallest angle in the triangle.
        //The smallest angle is opposite to the smallest side.
        Angle smallestAngle() const;

        //Returns the area of the triangle using the length of the smallest side.
        double area(double smallest_side) const;

        //Returns the lengths of the sides of the triangle in increasing order.
        Sides sides(double smallest_side) const;

        //Checks if the triangle is acute.
        bool acute() const;

        //Outputs to the console various facts about the triangle given the smallest side.
        void print(double smallest_side) const;

    };

}


#endif //ANGLE_TRIANGLE_H
