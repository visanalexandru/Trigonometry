//
// Created by visan on 3/4/22.
//

#ifndef ANGLE_ANGLE_H
#define ANGLE_ANGLE_H

#include<cmath>

namespace Trigonometry {

    const double RAD_PER_DEG = M_PI / 180;

    const double DEG_PER_RAD = 180 / M_PI;

    const double CIRCLE_SIZE_RAD = 2 * M_PI;

    const unsigned ARC_SEC_PER_MIN = 60;

    const unsigned ARC_SEC_PER_DEG = 3600;

    class Angle {
    private:
        double rad;

        //Returns the total of arc-seconds in the angle.
        unsigned get_total_seconds() const;

        //Clamps the given value of radians between [0,2*PI)
        static double adjust_angle(double radians);

    public:
        //Default constructor, create an angle of 0 radians.
        Angle();

        //Create an angle using radians.
        explicit Angle(double _radians);

        //Create an angle using sexagesimal measures.
        Angle(unsigned _degrees, unsigned _minutes, unsigned _seconds);

        //Get the number of radians.
        double radians() const;

        //Get the number of degrees.
        unsigned degrees() const;

        //Get the number of minutes.
        unsigned minutes() const;

        //Get the number of seconds.
        unsigned seconds() const;

        //Returns the cosine of the angle.
        double cos() const;

        //Returns the sine of the angle.
        double sin() const;
    };

    //Add two angles.
    Angle operator+(const Angle &a, const Angle &b);

    // Compare angles - greater.
    bool operator>(const Angle &a, const Angle &b);

    // Compare angles - greater or equal.
    bool operator>=(const Angle &a, const Angle &b);

    // Compare angles - smaller.
    bool operator<(const Angle &a, const Angle &b);

    // Compare angles - smaller or equal.
    bool operator<=(const Angle &a, const Angle &b);
}

#endif //ANGLE_ANGLE_H
