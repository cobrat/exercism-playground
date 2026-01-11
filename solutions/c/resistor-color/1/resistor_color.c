#include "resistor_color.h"

int color_code(resistor_band_t color) {
  return (int)color;
}

const resistor_band_t *color(void) {
  static const resistor_band_t all_colors[] = {
    BLACK,
    BROWN,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
  };
  return all_colors;
}
