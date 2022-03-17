#include <iostream>
#include<iomanip>
#include "Angle.h"
#include "Triangle.h"

void angle_example() {
    Trigonometry::Angle a1(23, 30, 10);
    Trigonometry::Angle a2(M_PI / 2);
    Trigonometry::Angle a0;
    Trigonometry::Angle a3 = a1 + a2;

    std::cout << a0 << std::endl;
    std::cout << a3 << std::endl;
    std::cout << std::fixed << std::setprecision(9) << a3.radians() << std::endl;
    std::cout << std::fixed << std::setprecision(9) << a2.cos() << std::endl;
}

void triangle_example() {
    Trigonometry::Angle a1(90, 30, 10), a2(60, 0, 0);
    double smallest_side = 3;
    Trigonometry::Triangle tri(a1, a2); // The triangle is initialized using two angles, the third one is supplementary.
    tri.print(smallest_side);

}

int main() {
    angle_example();
    triangle_example();
    return 0;
}
