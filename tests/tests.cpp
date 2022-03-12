//
// Created by visan on 3/12/22.
//
#define CATCH_CONFIG_MAIN

#include"catch.hpp"
#include<Angle.h>
#include<Triangle.h>

bool equal(double a, double b, double epsilon) {
    if (a < b) {
        std::swap(a, b);
    }
    return (a - b) < epsilon;
}

const double EPSILON = 0.000000001;

TEST_CASE("Angle construction from radians") {
    SECTION("Construct angle from a value in radians between [0 ,2*pi) radians") {
        Trigonometry::Angle a(0);
        REQUIRE(a.radians() == 0);
        REQUIRE(a.degrees() == 0);
        REQUIRE(a.minutes() == 0);
        REQUIRE(a.seconds() == 0);


        Trigonometry::Angle x(0.53);
        REQUIRE(x.radians() == 0.53);
        REQUIRE(x.degrees() == 30);
        REQUIRE(x.minutes() == 22);
        REQUIRE(x.seconds() == 0);

        Trigonometry::Angle y(4.231);
        REQUIRE(y.radians() == 4.231);
        REQUIRE(y.degrees() == 242);
        REQUIRE(y.minutes() == 25);
        REQUIRE(y.seconds() == 6);

        Trigonometry::Angle z(6.102234);
        REQUIRE(z.radians() == 6.102234);
        REQUIRE(z.degrees() == 349);
        REQUIRE(z.minutes() == 37);
        REQUIRE(z.seconds() == 56);
    }

    SECTION("Construct angle from a value in radians outside [0,2*pi)") {
        Trigonometry::Angle a(M_PI * 2);
        REQUIRE(a.radians() == 0);
        REQUIRE(a.degrees() == 0);
        REQUIRE(a.minutes() == 0);
        REQUIRE(a.seconds() == 0);

        Trigonometry::Angle b(7.98714);
        REQUIRE(equal(b.radians(), 1.703954693, EPSILON));
        REQUIRE(b.degrees() == 97);
        REQUIRE(b.minutes() == 37);
        REQUIRE(b.seconds() == 45);

        Trigonometry::Angle c(53);
        REQUIRE(equal(c.radians(), 2.734517543, EPSILON));
        REQUIRE(c.degrees() == 156);
        REQUIRE(c.minutes() == 40);
        REQUIRE(c.seconds() == 34);

        Trigonometry::Angle x(1234);
        REQUIRE(equal(x.radians(), 2.495679793, EPSILON));
        REQUIRE(x.degrees() == 142);
        REQUIRE(x.minutes() == 59);
        REQUIRE(x.seconds() == 30);

        Trigonometry::Angle y(90879);
        REQUIRE(equal(y.radians(), 5.290902262, EPSILON * 100));
        REQUIRE(y.degrees() == 303);
        REQUIRE(y.minutes() == 8);
        REQUIRE(y.seconds() == 46);

        Trigonometry::Angle d(-10);
        REQUIRE(equal(d.radians(), 2.56637061436, EPSILON));
    }
}

TEST_CASE("Angle construction from degrees, minutes and seconds") {
    Trigonometry::Angle a(123, 34, 23);
    REQUIRE(equal(a.radians(), 2.15675669, EPSILON * 100));
    REQUIRE(a.degrees() == 123);
    REQUIRE(a.minutes() == 34);
    REQUIRE(a.seconds() == 23);

    Trigonometry::Angle b(90, 54, 48);
    REQUIRE(equal(b.radians(), 1.586737, EPSILON * 100));
    REQUIRE(b.degrees() == 90);
    REQUIRE(b.minutes() == 54);
    REQUIRE(b.seconds() == 48);

    Trigonometry::Angle c(320, 11, 555);
    REQUIRE(equal(c.radians(), 5.59094409, EPSILON * 100));
    REQUIRE(c.degrees() == 320);
    REQUIRE(c.minutes() == 20);
    REQUIRE(c.seconds() == 15);

    Trigonometry::Angle x(899, 40, 30);
    REQUIRE(equal(x.radians(), 3.13592028564, EPSILON * 100));
    REQUIRE(x.degrees() == 179);
    REQUIRE(x.minutes() == 40);
}

TEST_CASE("Angle sine and cosine") {
    Trigonometry::Angle a(4.231);
    REQUIRE(equal(a.sin(), -0.88635266514, EPSILON));
    REQUIRE(equal(a.cos(), -0.46301074824, EPSILON));

    Trigonometry::Angle b(0.53);
    REQUIRE(equal(b.sin(), 0.5055333412, EPSILON));
    REQUIRE(equal(b.cos(), 0.86280707051, EPSILON));
}

TEST_CASE("Angle addition") {
    Trigonometry::Angle a(123, 45, 43);
    Trigonometry::Angle b(100, 24, 3);
    Trigonometry::Angle c = a + b;
    REQUIRE(c.degrees() == 224);
    REQUIRE(c.minutes() == 9);
    REQUIRE(c.seconds() == 46);

    Trigonometry::Angle x(3.24);
    Trigonometry::Angle y(-1.7);
    Trigonometry::Angle z = x + y;
    REQUIRE(z.radians() == 1.54);

    x = Trigonometry::Angle(23, 30, 10);
    y = Trigonometry::Angle(M_PI / 2);
    z = x + y;
    REQUIRE(equal(z.radians(), 1.9809971824, EPSILON));
    REQUIRE(z.degrees() == 113);
    REQUIRE(z.minutes() == 30);
    REQUIRE(z.seconds() == 10);
}

TEST_CASE("Angle comparison") {
    Trigonometry::Angle a(1.74);
    Trigonometry::Angle b(0.94);
    Trigonometry::Angle c(3.12);
    Trigonometry::Angle d(10, 20, 20);
    Trigonometry::Angle e(d.radians());
    REQUIRE(a > b);
    REQUIRE(a < c);
    REQUIRE(c > b);
    REQUIRE(d == e);
    REQUIRE(c != b);
}

TEST_CASE("Triangle smallest angle") {
    Trigonometry::Triangle a(Trigonometry::Angle(60, 0, 0), Trigonometry::Angle(40, 0, 0));
    REQUIRE(a.smallestAngle() == Trigonometry::Angle(40, 0, 0));

    Trigonometry::Triangle b(Trigonometry::Angle(90, 0, 0), Trigonometry::Angle(30, 0, 0));
    REQUIRE(b.smallestAngle() == Trigonometry::Angle(30, 0, 0));


    Trigonometry::Triangle c(Trigonometry::Angle(45, 30, 0), Trigonometry::Angle(89, 50, 0));
    Trigonometry::Angle smallest = c.smallestAngle();

    REQUIRE(smallest.degrees() == 44);
    REQUIRE(smallest.minutes() == 40);
    REQUIRE(smallest.seconds() == 0);
}

TEST_CASE("Triangle sides") {
    Trigonometry::Triangle a(Trigonometry::Angle(45, 0, 0), Trigonometry::Angle(90, 0, 0));
    Trigonometry::Triangle::Sides s = a.sides(3);
    REQUIRE(s.a == 3);
    REQUIRE(s.b == 3);
    REQUIRE(s.c == 3 * sqrt(2));

    Trigonometry::Triangle b(Trigonometry::Angle(1.6), Trigonometry::Angle(0.3));
    s = b.sides(23);
    REQUIRE(s.a == 23);
    REQUIRE(equal(s.b, 73.64945, 0.0001));
    REQUIRE(equal(s.c, 77.79567, 0.0001));
}

TEST_CASE("Triangle area") {
    Trigonometry::Triangle a(Trigonometry::Angle(60, 0, 0), Trigonometry::Angle(60, 0, 0));
    REQUIRE(equal(a.area(10), (100 * sqrt(3)) / 4, EPSILON));

    Trigonometry::Triangle b(Trigonometry::Angle(124, 0, 0), Trigonometry::Angle(44, 0, 0));

    REQUIRE(equal(b.area(1), 1.3849579284, 0.000001));

    Trigonometry::Triangle c(Trigonometry::Angle(0.5), Trigonometry::Angle(0.3));
    REQUIRE(equal(c.area(8), 37.240778532, 0.000001));
}

TEST_CASE("Triangle acute") {
    Trigonometry::Triangle a(Trigonometry::Angle(1.6), Trigonometry::Angle(0.3));
    REQUIRE(a.acute() == false);
    Trigonometry::Triangle b(Trigonometry::Angle(0.4), Trigonometry::Angle(1.2));
    REQUIRE(b.acute() == true);
    Trigonometry::Triangle c(Trigonometry::Angle(90, 0, 0), Trigonometry::Angle(30, 0, 0));
    REQUIRE(c.acute() == false);
    Trigonometry::Triangle d(Trigonometry::Angle(70, 0, 0), Trigonometry::Angle(30, 0, 0));
    REQUIRE(d.acute() == true);

}
