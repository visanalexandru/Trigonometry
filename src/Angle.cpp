//
// Created by visan on 3/4/22.
//

#include "Angle.h"

namespace Trigonometry {
    unsigned Angle::get_total_seconds() const {
        return (unsigned) round(rad * DEG_PER_RAD * ARC_SEC_PER_DEG);
    }

    double Angle::adjust_angle(double radians) {
        while (radians < 0) {
            radians += CIRCLE_SIZE_RAD;
        }
        while (radians >= CIRCLE_SIZE_RAD) {
            radians -= CIRCLE_SIZE_RAD;
        }
        return radians;
    }

    Angle::Angle() : rad(0) {

    }

    Angle::Angle(double _radians) : rad(adjust_angle(_radians)) {

    }

    Angle::Angle(unsigned _degrees, unsigned _minutes, unsigned _seconds) {
        double degrees = (double) _seconds / ARC_SEC_PER_DEG + (double) _minutes / ARC_SEC_PER_MIN + _degrees;
        rad = adjust_angle(degrees * RAD_PER_DEG);
    }

    double Angle::radians() const {
        return rad;
    }

    unsigned Angle::degrees() const {
        return get_total_seconds() / ARC_SEC_PER_DEG;
    }

    unsigned Angle::minutes() const {
        return (get_total_seconds() % ARC_SEC_PER_DEG) / ARC_SEC_PER_MIN;
    }

    unsigned Angle::seconds() const {
        return (get_total_seconds() % ARC_SEC_PER_DEG) % ARC_SEC_PER_MIN;
    }

    double Angle::cos() const {
        //Call cos function from the cmath library
        return ::cos(rad);
    }

    double Angle::sin() const {
        //Call sin function from the cmath library
        return ::sin(rad);
    }

    Angle operator+(const Angle &a, const Angle &b) {
        return Angle(a.radians() + b.radians());
    }

    Angle operator-(const Angle &a, const Angle &b) {
        return Angle(a.radians() - b.radians());
    }

    bool operator>(const Angle &a, const Angle &b) {
        return a.radians() > b.radians();
    }

    bool operator>=(const Angle &a, const Angle &b) {
        return a.radians() >= b.radians();
    }

    bool operator<(const Angle &a, const Angle &b) {
        return a.radians() < b.radians();
    }

    bool operator<=(const Angle &a, const Angle &b) {
        return a.radians() <= b.radians();
    }

    bool operator==(const Angle &a, const Angle &b) {
        return a.radians() == b.radians();
    }

    bool operator!=(const Angle &a, const Angle &b) {
        return a.radians() != b.radians();
    }
}
