#include "Vec4.hpp"

Vec4::Vec4() : x(0), y(0), z(0), u(0) {
}

Vec4::Vec4(double x, double y, double z, double u) : x(x), y(y), z(z), u(u) {
}

Vec4::~Vec4() {
}

double Vec4::magnitude() {
    return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vec4 Vec4::normalized() {
    // Will crash if magnitude is 0
    return *this / this->magnitude();
}

/*
 * Comparing
 */

bool operator == (const Vec4 & first, const Vec4 & second) {
    return first.x == second.x && first.y == second.y && first.z == second.z && first.u == second.u;
}

/*
 * Adding
 */

Vec4 operator + (const Vec4 & first, const Vec4 & second) {
    return Vec4(first.x + second.x, first.y + second.y, first.z + second.z, first.u + second.u);
}

Vec4 operator += (Vec4 & first, const Vec4 & second) {
    first.x += second.x;
    first.y += second.y;
    first.z += second.z;
    first.u += second.u;
    return first;
}

/*
 * Subtracting
 */

Vec4 operator - (const Vec4 & first, const Vec4 & second) {
    return Vec4(first.x - second.x, first.y - second.y, first.z - second.z, first.u - second.u);
}

Vec4 operator -= (Vec4 & first, const Vec4 & second) {
    first.x -= second.x;
    first.y -= second.y;
    first.z -= second.z;
    first.u -= second.u;
    return first;
}

/*
 * Multiplying
 */

Vec4 operator * (const Vec4 & first, const float second) {
    return Vec4(first.x * second, first.y * second, first.z * second, first.u * second);
}

Vec4 operator *= (Vec4 & first, const float second) {
    first.x *= second;
    first.y *= second;
    first.z *= second;
    first.u *= second;
    return first;
}

Vec4 operator * (float second, const Vec4 & first) {
    return first * second;
}

/*
 * Dividing
 */

Vec4 operator / (const Vec4 & first, const float second) {
    return Vec4(first.x / second, first.y / second, first.z / second, first.u / second);
}

Vec4 operator /= (Vec4 & first, const float second) {
    first.x /= second;
    first.y /= second;
    first.z /= second;
    first.u /= second;
    return first;
}

/*
 * Other
 */

double dot(Vec4 first, Vec4 second) {
    return first.x * second.x + first.y * second.y + first.z * second.z;
}

Vec4 cross(Vec4 first, Vec4 second) {
    return Vec4(first.y * second.z - first.z * second.y,
                first.z * second.x - first.x * second.z,
                first.x * second.y - first.y * second.x,
                0.0f);
}

double distance(Vec4 first, Vec4 second) {
    return std::sqrt(std::pow(first.x - second.x, 2) + std::pow(first.y - second.y, 2) + std::pow(first.z - second.z, 2));
}

bool lineIntersection(Vec4 a1, Vec4 a2, Vec4 b1, Vec4 b2, Vec4 & pos) {
    throwError("NotImplementedError", "bool lineIntersection(Vec4 a1, Vec4 a2, Vec4 b1, Vec4 b2, Vec4 & pos) is not implemented");
    return false;
}
