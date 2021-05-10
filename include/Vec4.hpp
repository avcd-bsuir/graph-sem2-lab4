#ifndef VEC4_HPP
#define VEC4_HPP

#include <cmath>
#include "utils.hpp"

class Vec4 {
    public:
        double x, y, z, u;

        Vec4();
        Vec4(double, double, double, double);
        ~Vec4();

        double magnitude();
        Vec4 normalized();
};

// Comapring
bool operator == (const Vec4 & first, const Vec4 & second);

// Adding
Vec4 operator + (const Vec4 & first, const Vec4 & second);
Vec4 operator += (Vec4 & first, const Vec4 & second);

// Subtracting
Vec4 operator - (const Vec4 & first, const Vec4 & second);
Vec4 operator -= (Vec4 & first, const Vec4 & second);

// Multiplying
Vec4 operator * (const Vec4 & first, const float second);
Vec4 operator *= (Vec4 & first, const float second);
Vec4 operator * (const float second, const Vec4 & first);

// Dividing
Vec4 operator / (const Vec4 & first, const float second);
Vec4 operator /= (Vec4 & first, const float second);

// Other
double dot(Vec4, Vec4);
Vec4 cross(Vec4, Vec4);
double distance(Vec4, Vec4);
bool lineIntersection(Vec4, Vec4, Vec4, Vec4, Vec4 &);

#endif
