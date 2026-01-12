#include "resistor_color_duo.h"

int color_code(resistor_band_t color[]) {
    int r1 = 0, r2 = 0;

    r1 = (int)color[0];
    r2 = (int)color[1];

    return r1 * 10 + r2;
}
