#include "grains.h"
#include <math.h>
#include <stdint.h>

uint64_t square(uint8_t index) {
  uint64_t count = 0;
  if (index <= 64) {
      count = (uint64_t)pow(2, index - 1);
  }
  return count;
}

uint64_t total(void) {
  uint64_t i = 0;
  uint64_t sum = 0;

  while (i <= 64) {
    sum += square(i);
    i++;
  }
  return sum;
}
