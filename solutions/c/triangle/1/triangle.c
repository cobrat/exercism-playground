#include "triangle.h"
#include <math.h>
#include <stdbool.h>

#define EPSILON 1e-9

static inline bool double_equal(double a, double b) {
    return fabs(a - b) < EPSILON;
}

static inline bool is_valid(triangle_t t) {
    return (t.a > 0 && t.b > 0 && t.c > 0) && (t.a + t.b > t.c) &&
           (t.a + t.c > t.b) && (t.c + t.b > t.a);
}

bool is_equilateral(triangle_t t) {
    return is_valid(t) && double_equal(t.a, t.b) && double_equal(t.b, t.c);
}

bool is_isosceles(triangle_t t) {
    return is_valid(t) && (double_equal(t.a, t.b) || double_equal(t.b, t.c) ||
                           double_equal(t.a, t.c));
}

bool is_scalene(triangle_t t) {
    return is_valid(t) && !double_equal(t.a, t.b) && !double_equal(t.b, t.c) &&
           !double_equal(t.a, t.c);
}
