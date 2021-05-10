#ifndef MAT4_HPP
#define MAT4_HPP

#include <array>

#include "Vec4.hpp"

class Mat4 {
    private:
    public:
        std::array<double, 16> data;

        Mat4();
        Mat4(std::array<double, 16>);
        Mat4(double);
        Mat4(double, double, double, double);
        Mat4(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double);
        ~Mat4();

        double determinant();
};

// Comapring
bool operator == (const Mat4 & first, const Mat4 & second);

// Adding
Mat4 operator + (const Mat4 & first, const Mat4 & second);
Mat4 operator += (Mat4 & first, const Mat4 & second);

// Subtracting
Mat4 operator - (const Mat4 & first, const Mat4 & second);
Mat4 operator -= (Mat4 & first, const Mat4 & second);

// Multiplying
Mat4 operator * (const Mat4 & first, const Mat4 & second);
Mat4 operator *= (Mat4 & first, const Mat4 & second);
Vec4 operator * (const Mat4 & first, const Vec4 & second);
Vec4 operator * (const Vec4 & first, const Mat4 & second);

Mat4 operator * (const Mat4 & first, const float second);
Mat4 operator *= (Mat4 & first, const float second);
Mat4 operator * (const float second, const Mat4 & first);

// Dividing
Mat4 operator / (const Mat4 & first, const float second);
Mat4 operator /= (Mat4 & first, const float second);

#endif
