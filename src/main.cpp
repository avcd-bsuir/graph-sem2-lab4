// License: CC BY-NC-SA 4.0
/*
 * main.cpp
 *
 * This file should be used as a template file.
 *
 * Written by AlexeyFilich
 * 10 mar 2021
 */

#include <cmath>
#include <iostream>
#include <vector>

#include "Color.hpp"
#include "Engine.hpp"
// #include "MakeString.hpp"
#include "Mat3.hpp"
#include "Mat4.hpp"
#include "primitives.hpp"
#include "utils.hpp"
#include "Vec3.hpp"
#include "Vec4.hpp"

#define WIDTH 1280
#define HEIGHT 720

Mat4 rotate(double angle, Vec4 axis) {
    axis = axis.normalized();
    const double a = angle;
    const double c = std::cos(a);
    const double s = std::sin(a);

    Vec4 temp = (1 - c) * axis;
    Mat4 rot(1.0f, 1.0f, 1.0f, 1.0f);

    rot.data[0] = c + temp.x * axis.x;
    rot.data[1] = temp.y * axis.x - s * axis.z;
    rot.data[2] = temp.z * axis.x + s * axis.y;
    rot.data[4] = temp.x * axis.y + s * axis.z;
    rot.data[5] = c + temp.y * axis.y;
    rot.data[6] = temp.z * axis.y - s * axis.x;
    rot.data[8] = temp.x * axis.z - s * axis.y;
    rot.data[9] = temp.y * axis.z + s * axis.x;
    rot.data[10] = c + temp.z * axis.z;

    return rot;
}

int main(int argc, char* args[]) {
    Engine engine("Lab 4", WIDTH, HEIGHT, Color(0x0));
    int x, y;

    std::vector<std::pair<Vec4, Vec4>> cube {
        {Vec4(+0.5f, +0.5f, +0.5f, 0.0f), Vec4(-0.5f, +0.5f, +0.5f, 0.0f)},
        {Vec4(-0.5f, +0.5f, +0.5f, 0.0f), Vec4(-0.5f, -0.5f, +0.5f, 0.0f)},
        {Vec4(-0.5f, -0.5f, +0.5f, 0.0f), Vec4(+0.5f, -0.5f, +0.5f, 0.0f)},
        {Vec4(+0.5f, -0.5f, +0.5f, 0.0f), Vec4(+0.5f, +0.5f, +0.5f, 0.0f)},
        {Vec4(+0.5f, +0.5f, +0.5f, 0.0f), Vec4(+0.5f, +0.5f, -0.5f, 0.0f)},
        {Vec4(-0.5f, +0.5f, +0.5f, 0.0f), Vec4(-0.5f, +0.5f, -0.5f, 0.0f)},
        {Vec4(-0.5f, -0.5f, +0.5f, 0.0f), Vec4(-0.5f, -0.5f, -0.5f, 0.0f)},
        {Vec4(+0.5f, -0.5f, +0.5f, 0.0f), Vec4(+0.5f, -0.5f, -0.5f, 0.0f)},
        {Vec4(+0.5f, +0.5f, -0.5f, 0.0f), Vec4(-0.5f, +0.5f, -0.5f, 0.0f)},
        {Vec4(-0.5f, +0.5f, -0.5f, 0.0f), Vec4(-0.5f, -0.5f, -0.5f, 0.0f)},
        {Vec4(-0.5f, -0.5f, -0.5f, 0.0f), Vec4(+0.5f, -0.5f, -0.5f, 0.0f)},
        {Vec4(+0.5f, -0.5f, -0.5f, 0.0f), Vec4(+0.5f, +0.5f, -0.5f, 0.0f)},
    };
    std::vector<std::pair<Vec4, Vec4>> cube_transformed(cube.size());

    const int scale_factor = 300.0f;
    // double angle_x = M_PI / 4.0f;
    // double angle_y = M_PI / 4.0f;
    double angle_x = 0.0f;
    double angle_y = 0.0f;
    double angle_z = 0.0f;
    double angle_a = 0.0f;

    Mat4 Rx = rotate(angle_x, Vec4(1.0f, 0.0f, 0.0f, 0.0f));
    Mat4 Ry = rotate(angle_y, Vec4(0.0f, 1.0f, 0.0f, 0.0f));
    Mat4 Rz = rotate(angle_z, Vec4(0.0f, 0.0f, 1.0f, 0.0f));
    Mat4 Ra(1.0f, 1.0f, 1.0f, 1.0f);
    Mat4 A = Rx * Ry * Rz * Ra;

    while (!engine.shouldExit()) {
        SDL_Event event;
        while (engine.pollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE: engine.shutdown(); break;
                    case SDL_SCANCODE_Q:
                        angle_x += M_PI / 64.0f;
                        Rx = rotate(angle_x, Vec4(1.0f, 0.0f, 0.0f, 0.0f));
                        break;
                    case SDL_SCANCODE_A:
                        angle_x -= M_PI / 64.0f;
                        Rx = rotate(angle_x, Vec4(1.0f, 0.0f, 0.0f, 0.0f));
                        break;
                    case SDL_SCANCODE_W:
                        angle_y += M_PI / 64.0f;
                        Ry = rotate(angle_y, Vec4(0.0f, 1.0f, 0.0f, 0.0f));
                        break;
                    case SDL_SCANCODE_S:
                        angle_y -= M_PI / 64.0f;
                        Ry = rotate(angle_y, Vec4(0.0f, 1.0f, 0.0f, 0.0f));
                        break;
                    case SDL_SCANCODE_E:
                        angle_z += M_PI / 64.0f;
                        Rz = rotate(angle_z, Vec4(0.0f, 0.0f, 1.0f, 0.0f));
                        break;
                    case SDL_SCANCODE_D:
                        angle_z -= M_PI / 64.0f;
                        Rz = rotate(angle_z, Vec4(0.0f, 0.0f, 1.0f, 0.0f));
                        break;
                    case SDL_SCANCODE_R:
                        angle_a += M_PI / 64.0f;
                        // Ra = rotate(angle_a, cube[1].first);
                        Ra = rotate(angle_a, cube_transformed[1].first);
                        break;
                    case SDL_SCANCODE_F:
                        angle_a -= M_PI / 64.0f;
                        // Ra = rotate(angle_a, cube[1].first);
                        Ra = rotate(angle_a, cube_transformed[1].first);
                        break;
                    default: log("Event", "SDL_KEYDOWN event processed"); break;
                }
                A = Rx * Ry * Rz * Ra;
            }
        }

        engine.clear();

        SDL_GetMouseState(&x, &y);

        // Axes
        drawLine(&engine, WIDTH / 2 - 300.0f, HEIGHT / 2, WIDTH / 2 + 300.0f, HEIGHT / 2, Color(128, 128, 128), 0xFC30FC30);
        drawLine(&engine, WIDTH / 2, HEIGHT / 2 - 300.0f, WIDTH / 2, HEIGHT / 2 + 300.0f, Color(128, 128, 128), 0xFC30FC30);
        drawLine(&engine, WIDTH / 2, HEIGHT / 2, WIDTH / 2 - 300.0f, HEIGHT / 2 + 300.0f, Color(128, 128, 128), 0xFC30FC30);
        drawLine(&engine, cube_transformed[1].first.y, cube_transformed[1].first.z, cube_transformed[11].first.y, cube_transformed[11].first.z, Color(128, 128, 128), 0xFC30FC30);

        // Get cube transformed points
        Vec4 min(0.0f, 0.0f, 0.0f, 0.0f);
        for (int i = 0; i < cube.size(); i++) {
            cube_transformed[i].first = cube[i].first * A * scale_factor + Vec4(0.0f, WIDTH / 2, HEIGHT / 2, 0.0f);
            cube_transformed[i].second = cube[i].second * A * scale_factor + Vec4(0.0f, WIDTH / 2, HEIGHT / 2, 0.0f);
            if (cube_transformed[i].first.x > min.x)
                min = cube_transformed[i].first;
        }

        // Draw cube
        for (int i = 0; i < cube_transformed.size(); i++) {
            Vec4 a = cube_transformed[i].first;
            Vec4 b = cube_transformed[i].second;
            int pattern = 0xFFFFFFFF;
            if (a == min || b == min)
                pattern = 0xFF00FF00;
            drawLine(&engine, a.y, a.z, b.y, b.z, Color(255, 255, 255), pattern);
        }

        engine.draw();
        SDL_Delay(16);
    }
    return 0;
}
