#include "primitives.hpp"

void drawLine(Engine * engine, double x1, double y1, double x2, double y2, Color c1, Color c2, uint32_t pattern) {
    #ifdef LINE_LERP
    double dots = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    for (double u = 0.0f; u < 1.0f; u += 1 / dots)
        engine->setPixel(std::round(lerp(x1, x2, u)), std::round(lerp(y1, y2, u)), lerp(c1, c2, u));
    #endif

    #ifdef LINE_DIGITAL_DIFFERENTIAL_ANALYZER
    int x, y;
    int dx = x2 - x1, dy = y2 - y1;

    auto should_draw = [&]() {
        pattern = (pattern << 1) | (pattern >> 31);
        return pattern & 1;
    };

    if (dx == 0) {
        if (y2 < y1)
            std::swap(y1, y2);
        for (int y = y1; y <= y2; y++)
            if (should_draw())
                engine->setPixel(x1, y, lerp(c1, c2, (y - y1) / dy));
        return;
    }

    if (dy == 0) {
        if (x2 < x1)
            std::swap(x1, x2);
        for (int x = x1; x <= x2; x++)
            if (should_draw())
                engine->setPixel(x, y1, lerp(c1, c2, (x - x1) / dx));
        return;
    }

    int adx = std::abs(dx), ady = std::abs(dy);
    int px = 2 * ady - adx, py = 2 * adx - ady;
    int xe, ye;

    if (ady <= adx) {
        if (dx >= 0) {
            x = x1;
            y = y1;
            xe = x2;
        } else {
            x = x2;
            y = y2;
            xe = x1;
        }

        if (should_draw())
            engine->setPixel(x, y, lerp(c2, c1, (std::pow(x - x2, 2) - std::pow(y - y2, 2)) / (std::pow(x1 - x2, 2) - std::pow(y1 - y2, 2))));

        while (x < xe) {
            x++;
            if (px < 0) {
                px = px + 2 * ady;
            } else {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                    y++;
                else
                    y--;
                px = px + 2 * (ady - adx);
            }
            if (should_draw())
                engine->setPixel(x, y, lerp(c2, c1, (std::pow(x - x2, 2) - std::pow(y - y2, 2)) / (std::pow(x1 - x2, 2) - std::pow(y1 - y2, 2))));
        }
    } else {
        if (dy >= 0) {
            x = x1;
            y = y1;
            ye = y2;
        } else {
            x = x2;
            y = y2;
            ye = y1;
        }

        if (should_draw())
            engine->setPixel(x, y, lerp(c2, c1, (std::pow(x - x2, 2) - std::pow(y - y2, 2)) / (std::pow(x1 - x2, 2) - std::pow(y1 - y2, 2))));

        while (y < ye) {
            y++;
            if (py <= 0)
                py = py + 2 * adx;
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                    x++;
                else
                    x--;
                py = py + 2 * (adx - ady);
            }
            if (should_draw())
                engine->setPixel(x, y, lerp(c2, c1, (std::pow(x - x2, 2) - std::pow(y - y2, 2)) / (std::pow(x1 - x2, 2) - std::pow(y1 - y2, 2))));
        }
    }
    #endif
}

void drawLine(Engine * engine, double x1, double y1, double x2, double y2, Color c, uint32_t pattern) {
    drawLine(engine, x1, y1, x2, y2, c, c, pattern);
}

void drawLine(Engine * engine, Vec3 first, Vec3 second, Color c1, Color c2, uint32_t pattern) {
    drawLine(engine, first.x, first.y, second.x, second.y, c1, c2, pattern);
}

void drawLine(Engine * engine, Vec3 first, Vec3 second, Color c, uint32_t pattern) {
    drawLine(engine, first.x, first.y, second.x, second.y, c, c, pattern);
}
