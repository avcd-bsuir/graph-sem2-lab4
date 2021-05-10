#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include <cstdint>

#include "Color.hpp"
#include "Engine.hpp"
#include "utils.hpp"
#include "Vec3.hpp"

#define LINE_DIGITAL_DIFFERENTIAL_ANALYZER

void drawLine(Engine *, double, double, double, double, Color, Color, uint32_t);
void drawLine(Engine *, double, double, double, double, Color, uint32_t);
void drawLine(Engine *, Vec3, Vec3, Color, Color, uint32_t);
void drawLine(Engine *, Vec3, Vec3, Color, uint32_t);

#endif
