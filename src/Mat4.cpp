#include "Mat4.hpp"

Mat4::Mat4() {
    this->data = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
}

Mat4::Mat4(std::array<double, 16> data) {
    this->data = data;
}

Mat4::Mat4(double a) {
    this->data = { a, a, a, a, a, a, a, a, a, a, a, a, a, a, a, a };
}

Mat4::Mat4(double a, double b, double c, double d) {
    this->data = { a, 0, 0, 0,
                   0, b, 0, 0,
                   0, 0, c, 0,
                   0, 0, 0, d };
}

Mat4::Mat4(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j, double k, double l, double m, double n, double o, double p) {
    this->data = { a, b, c, d,
                   e, f, g, h,
                   i, j, k, l,
                   m, n, o, p };
}

Mat4::~Mat4() {
}

double Mat4::determinant() {;
    throwError("NotImplementedError", "Mat4::determinant() is not implemented");
    return 0.0f;
}

/*
 * Comparing
 */

bool operator == (const Mat4 & first, const Mat4 & second) {
    return first.data == second.data;
}

/*
 * Adding
 */

Mat4 operator + (const Mat4 & first, const Mat4 & second) {
    std::array<double, 16> data;
    for (int i = 0; i < 16; i++)
        data[i] = first.data[i] + second.data[i];
    return Mat4(data);
}

Mat4 operator += (Mat4 & first, const Mat4 & second) {
    for (int i = 0; i < 16; i++)
        first.data[i] += second.data[i];
    return first;
}

/*
 * Subtracting
 */

Mat4 operator - (const Mat4 & first, const Mat4 & second) {
    std::array<double, 16> data;
    for (int i = 0; i < 16; i++)
        data[i] = first.data[i] - second.data[i];
    return Mat4(data);
}

Mat4 operator -= (Mat4 & first, const Mat4 & second) {
    for (int i = 0; i < 16; i++)
        first.data[i] -= second.data[i];
    return first;
}

/*
 * Multiplying
 */

Mat4 operator * (const Mat4 & first, const Mat4 & second) {
    std::array<double, 16> result;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i + j * 4] = 0.0f;
            for (int k = 0; k < 4; k++)
                result[i + j * 4] += second.data[i + k * 4] * first.data[k + j * 4];
        }
    }
    return Mat4(result);
}

Mat4 operator *= (Mat4 & first, const Mat4 & second) {
    first = first * second;
    return first;
}

Vec4 operator * (const Mat4 & first, const Vec4 & second) {
    return Vec4(first.data[0] * second.x + first.data[1] * second.y + first.data[2] * second.z + first.data[3] * second.u,
                first.data[4] * second.x + first.data[5] * second.y + first.data[6] * second.z + first.data[7] * second.u,
                first.data[8] * second.x + first.data[9] * second.y + first.data[10] * second.z + first.data[11] * second.u,
                first.data[12] * second.x + first.data[13] * second.y + first.data[14] * second.z + first.data[15] * second.u);
}

Vec4 operator * (const Vec4 & first, const Mat4 & second) {
    return Vec4(first.x * second.data[0] + first.y * second.data[4] + first.z * second.data[8] + first.u * second.data[12],
                first.x * second.data[1] + first.y * second.data[5] + first.z * second.data[9] + first.u * second.data[13],
                first.x * second.data[2] + first.y * second.data[6] + first.z * second.data[10] + first.u * second.data[14],
                first.x * second.data[3] + first.y * second.data[7] + first.z * second.data[11] + first.u * second.data[15]);
}

Mat4 operator * (const Mat4 & first, const float second) {
    std::array<double, 16> data;
    for (int i = 0; i < 16; i++)
        data[i] = first.data[i] * second;
    return Mat4(data);
}

Mat4 operator *= (Mat4 & first, const float second) {
    for (int i = 0; i < 16; i++)
        first.data[i] *= second;
    return first;
}

Mat4 operator * (float second, const Mat4 & first) {
    return first * second;
}

/*
 * Dividing
 */

Mat4 operator / (const Mat4 & first, const float second) {
    std::array<double, 16> data;
    for (int i = 0; i < 16; i++)
        data[i] = first.data[i] / second;
    return Mat4(data);
}

Mat4 operator /= (Mat4 & first, const float second) {
    for (int i = 0; i < 16; i++)
        first.data[i] /= second;
    return first;
}
