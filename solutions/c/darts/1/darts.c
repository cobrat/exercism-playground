#include "darts.h"

int score(coordinate_t position) {
    float radius = position.x * position.x + position.y * position.y;
    int score = 0;

    if (radius > 10 * 10) {
        score = 0;
    } else if (radius > 5 * 5) {
        score = 1;
    } else if (radius > 1 * 1) {
        score = 5;
    } else {
        score = 10;
    }

    return score;
}
